#include <type_traits>

// is_instance
template <class, template <class> class>
struct is_instance : public std::false_type {};

template <class T, template <class> class U>
constexpr bool is_instance_v = is_instance<T, U>::value;

template <class T, template <class> class U>
struct is_instance<U<T>, U> : public std::true_type {};

// is_field
template <class T>
struct is_field : public std::false_type {};

template <class T>
constexpr bool is_field_v = is_field<T>::value;

template <typename T>
struct Denom {
	using type = T;
};

template <typename T>
using Denom_t = typename Denom<T>::type;

template <typename F>
constexpr void FactorNumber(long long n, F f) {
	for(long long p = 2; p * p <= n; ++p)
		if(n % p == 0) {
			int e = 0;
			while(n % p == 0) n /= p, ++e;
			if constexpr(std::is_same_v<bool, std::invoke_result_t<F, long long, long long>>) {
				if(!f(p, e)) return;
			} else
				f(p, e);
		}
	if(n > 1) f(n, 1);
}

template <typename T>
constexpr bool IsPrime(T n) {
	int fs = 0;
	FactorNumber(n, [&](long long p, long long e) { return ++fs == 1; });
	return fs == 1;
}

constexpr long long Phi(long long n) {
	FactorNumber(n, [&](long long p, long long e) { return n = n / p * (p - 1); });
	return n;
}

constexpr long long Gcd(long long a, long long b) { return a == 0 ? b : Gcd(b % a, a); }

#include <cassert>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<int>;
template <typename T>
T gcd(T a, T b) {
	while(b != T{0}) {
		a = a % b;
		swap(a, b);
	}
	return a;
}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
template <typename T>
constexpr T mod(T a, T b) {
	return ((a % b) + b) % b;
}
// Finds x, y s.t. ax + by = d = gcd(a, b).
template <typename T>
constexpr void extended_euclid(T a, T b, T& x, T& y, T& d) {
	if(b == 0)
		x = a > 0 ? 1 : -1, y = 0, d = (a < 0 ? -a : a);
	else
		extended_euclid(b, a % b, y, x, d), y -= a / b * x;
}
template <typename T>
pair<T, T> crt(T a1, T m1, T a2, T m2) {
	T s, t, d;
	extended_euclid(m1, m2, s, t, d);
	if(a1 % d != a2 % d) {
		// cerr << "Modulus " << d << "  with remainders " << a1 << " and " << a2 << endl;
		return {-1, 0};
	}
	auto r = mod(s * a2 % m2 * m1 + t * a1 % m1 * m2, m1 * m2) / d;
	auto m = m1 / d * m2;
	return {r, m};
}

// solves ab = 1 (mod n), -1 on failure
constexpr ll mod_inverse(ll a, ll n) {
	ll x = 0, y = 0, d = 0;
	extended_euclid(a, n, x, y, d);
	return (d > 1 ? -1 : mod(x, n));
}
// All modular inverses of [1..n] mod P in O(n) time.
vi inverses(ll n, ll P) {
	vi I(n + 1, 1LL);
	for(ll i = 2; i <= n; ++i) I[i] = mod(-(P / i) * I[P % i], P);
	return I;
}
// (a*b)%m
ll mulmod(ll a, ll b, ll m) {
	return __int128(a) * b % m;
	b %= m;
	ll x = 0, y = a % m;
	while(b > 0) {
		if(b & 1) x = (x + y) % m;
		y = (2 * y) % m, b /= 2;
	}
	return x % m;
}

template <typename T>
struct Poly;

// Finds b^e in O(lg n) time
template <bool no_inverse = false, typename T = long long>
constexpr T pow(T b, ll e, const T& id = T{1}) {
	if constexpr(std::is_integral_v<T> || is_instance<T, Poly>::value || no_inverse) {
		assert(e >= 0);
	} else {
		if(e < 0) {
			auto x = pow<no_inverse>(b, -e, id);
			// cerr << "POW: "<< e << " from " << x << " to " << 1/x << endl;
			return 1 / x;
		}
	}
	T p = e < 2 ? id : pow<no_inverse>(b * b, e / 2, id);
	return e & 1 ? p * b : p;
}
template <typename T, typename M>
constexpr T pow(T b, ll e, const T& id, const M& m) {
	// if(e < 0) return 1/pow(b, -e, id, m);
	T p = e < 2 ? id : pow(m(b, b), e / 2, id, m);
	return e & 1 ? m(p, b) : p;
}
// Alias to avoid issues with the std pow.
template <typename T>
constexpr T binpow(T b, ll e, T id = T(1)) {
	return ::pow<T>(b, e, id);
}
// Finds b^e % m in O(lg n) time, ensure that b < m to avoid overflow!
template <typename T = long long>
constexpr T powmod(T b, ll e, T m) {
	T p = e < 2 ? T{1} : powmod((b * b) % m, e / 2, m);
	return e & 1 ? p * b % m : p;
}
// Solve ax + by = c, returns false on failure.
bool linear_diophantine(ll a, ll b, ll c, ll& x, ll& y) {
	ll d = gcd(a, b);
	if(c % d) {
		return false;
	} else {
		x = c / d * mod_inverse(a / d, b / d);
		y = (c - a * x) / b;
		return true;
	}
}

#include <ostream>

template <auto P, typename B = long long> // prime, primitive root
struct Field {
	constexpr static B p = P;
	using T              = Field;
	using B_             = B;

  private:
	B x;

  public:
	constexpr Field(B x = 0) : x{x % p} {}

	template <auto M2, typename B2 = long long>
	constexpr Field(Field<M2, B2> b) : x{b.x % p} {
		static_assert(M2 % p == 0);
	}

	constexpr T operator+(T r) const { return (x + r.x) % p; }
	constexpr T& operator+=(T r) { return x = (x + r.x) % p, *this; }
	constexpr T operator-() const { return (-x) % p; }
	constexpr T operator-(T r) const { return (x - r.x) % p; }
	constexpr T& operator-=(T r) { return x = (x + p - r.x) % p, *this; }
	constexpr T operator*(T r) const { return (x % p * r.x) % p; }
	constexpr T& operator*=(T r) { return x = (x % p * r.x) % p, *this; }
	constexpr T operator/(T r) const { return (*this) * r.inv(); }
	constexpr T& operator/=(T r) { return (*this) *= r.inv(); }
	constexpr bool operator==(T r) const { return (x - r.x) % p == 0; }

	constexpr B operator%(B r) const {
		assert(P % r == 0);
		return val() % r;
	}

	constexpr friend T operator+(T l, B r) { return (l.x + r) % p; }
	constexpr friend T operator+(B l, T r) { return (l + r.x) % p; }
	constexpr T& operator+=(B r) { return x = (x + r) % p, *this; }
	constexpr friend T operator-(T l, B r) { return (l.x - r + p) % p; }
	constexpr friend T operator-(B l, T r) { return (l - r.x + p) % p; }
	constexpr T& operator-=(B r) { return x = (x + p - r) % p, *this; }
	constexpr friend T operator*(T l, B r) { return (l.x * (r % p)) % p; }
	constexpr friend T operator*(B l, T r) { return ((l % p) * r.x) % p; }
	constexpr T& operator*=(B r) { return x = (x * r) % p, *this; }
	constexpr friend T operator/(T l, B r) { return l * T{r}.inv(); }
	constexpr friend T operator/(B l, T r) { return l * r.inv(); }
	constexpr T& operator/=(B r) { return (*this) *= T{r}.inv(); }
	constexpr bool operator==(B r) const { return (x - r) % p == 0; }

	constexpr T& operator++() {
		++x;
		return *this;
	}

	B val() const { return ((x % p) + p) % p; }
	B val_fast_unsafe() const { return x; }

	constexpr T inv() const {
		// static_assert(IsPrime(p));
		assert(x != 0);
		auto i = mod_inverse(x, p);
		assert(i != -1);
		return i;
	} // pow(x, p-2) is 6x slower
	static T root(B k) {
		assert((p - 1) % k == 0);
		constexpr auto w = primitive_root();
		if(k > 0)
			return pow(w, (p - 1) / k);
		else
			return pow(w, (p - 1) / -k).inv();
	}
	static constexpr T primitive_root() {
		static_assert(IsPrime(p));
		T w = 2;
		while(true) {
			auto r  = p - 1;
			bool ok = true;
			for(long long q = 2; q * q <= r; ++q)
				if(r % q == 0) {
					while(r % q == 0) r /= q;
					if(pow(w, (p - 1) / q).x == 1) {
						ok = false;
						break;
					}
				}
			if(r > 1 && pow(w, (p - 1) / r).x == 1) ok = false;
			if(ok) return w.x;
			w += 1;
		}
	}
	bool zero() const { return x == 0LL; }
	// operator B(){return x;}
	constexpr T sqrt() const {
		auto y = sqrtp(x, p);
		assert(y >= 0);
		return {y};
	}
	friend T sqrt(T t) { return t.sqrt(); }
	friend ostream& operator<<(std::ostream& o, T t) { return o << (t.x + p) % p; }

	struct comp {
		bool operator()(const T& l, const T& r) const { return l.val() < r.val(); }
	};

	template <B Q>
	constexpr Field<P * Q, B> Multiply() {
		return x * Q;
	}

	template <auto D>
	constexpr Field<P / D, B> Div() {
		static_assert(P % D == 0);
		assert(x % D == 0);
		return x / D;
	}

	template <auto, typename>
	friend class Field;

	template <auto, auto, typename, typename>
	friend struct FieldFrac;
};

template <auto P, typename B = long long> // prime, primitive root
auto abs(Field<P, B> f) {
	return f.val();
}

using F1 = Field<1'107'296'257>; // k * 2^25 + 1
using F2 = Field<2'013'265'921>; // k * 2^27 + 1
using F3 = Field<2'281'701'377>; // k * 2^27 + 1

// Specializations of Pow for Field.
template <auto M, typename B = long long, auto M2 = Phi(M), typename B2 = long long>
constexpr Field<M> pow(Field<M, B> b, Field<M2, B2> e) {
	static_assert(M2 % Phi(M) == 0);
	return pow(b, e.x);
}

// TODO: Make this work for non-coprime A and B.
template <typename T = long long, T P, T Q>
constexpr auto crt(Field<P, T> a, Field<Q, T> b) {
	using A = Field<P, T>;
	using B = Field<Q, T>;
	static_assert(Gcd(A::p, B::p) == 1);
	return (a / B::p).template Multiply<B::p>() + (b / A::p).template Multiply<A::p>();
}
template <typename T = long long, T P, T Q>
constexpr auto operator&(Field<P, T> a, Field<Q, T> b) {
	return crt(a, b);
}

template <auto P, class B>
struct is_field<Field<P, B>> : public std::true_type {};

////////////////////////////////////////////////////////////////////////////////

template <typename B = long long>
struct field {
	using T = field;
	const B p;
	B x;
	field(B x = 0) : p{p_}, x{x % p} {}
	field(B x, B p) : p{p}, x{x % p} {}
	field(B x, B p, B w) : p{p}, x{x % p} {}

  private:
	struct nofield {};
	field(nofield) : p{0}, x{0} {}

  public:
	bool ok() { return p != 0; }

	field& operator=(const field& r) {
		assert(p == r.p);
		x = r.x;
		return *this;
	}

	T operator+(T r) const {
		assert(p == r.p);
		return {(x + r.x + p) % p, p};
	}
	T& operator+=(T r) {
		assert(p == r.p);
		return x = (x + p + r.x) % p, *this;
	}
	friend T operator+(B l, T r) { return {(l + r.x + r.p) % r.p, r.p}; }
	friend T operator+(T l, B r) { return {(l.x + r + l.p) % l.p, l.p}; }

	T operator-() const { return {(-x + p) % p, p}; }

	T operator-(T r) const {
		assert(p == r.p);
		return {(x - r.x + p) % p, p};
	}
	T& operator-=(T r) {
		assert(p == r.p);
		return x = (x + p - r.x) % p, *this;
	}
	friend T operator-(B l, T r) { return {(l - r.x + r.p) % r.p, r.p}; }
	friend T operator-(T l, B r) { return {(l.x - r + l.p) % l.p, l.p}; }

	T operator*(T r) const {
		assert(p == r.p);
		return {(x * r.x) % p, p};
	}
	T& operator*=(T r) {
		assert(p == r.p);
		return x = (x * r.x) % p, *this;
	}
	friend T operator*(B l, T r) { return {(l * r.x) % r.p, r.p}; }
	friend T operator*(T l, B r) { return {(l.x * r) % l.p, l.p}; }

	T operator/(T r) const {
		assert(p == r.p);
		return (*this) * r.inv();
	}
	T& operator/=(T r) {
		assert(p == r.p);
		return *this *= r.inv();
	}
	bool operator==(T r) const {
		assert(p == r.p);
		return (x - r.x) % p == 0;
	}
	bool operator!=(T r) const { return !(x == r.x); }

	T& operator+=(B r) { return x = (x + r) % p, *this; }
	T& operator-=(B r) { return x = (x + p - r) % p, *this; }
	T& operator*=(B r) { return x = (x * r) % p, *this; }
	T operator/(B r) const { return (*this) * T{r, p}.inv(); }
	T& operator/=(B r) { return *this *= T{r, p}.inv(); }
	bool operator==(B r) const { return x == r; }
	bool operator!=(B r) const { return x != r; }

	B val() const {
		auto r = ((x % p) + p) % p;
		assert(r >= 0);
		return r;
	}

	friend T operator&(T l, T r) {
		auto [x, p] = crt(l.val(), l.p, r.val(), r.p);
		if(p == 0) return field(nofield());
		return field(x, p);
	}

	T inv() const {
		assert(x != 0);
		if(p == cache_p_ and x < cache_.size()) return {cache_[x], p};
		return {mod_inverse(x, p), p};
		// return pow(*this, p-2); // 4x slower
	}
	T root(B k) {
		assert((p - 1) % k == 0);
		assert(false); // (p-1)%k == 0?
		               // auto r = powmod(w,(p-1)/abs(k),p);				// k-th root
		               // of
		               // unity return k>=0 ? T{r} : T{r}.inv();
	}
	bool zero() const { return x == 0LL; }
	// operator B(){return x;}
	friend ostream& operator<<(std::ostream& o, T t) { return o << t.x; }
	static B p_;
	static B cache_p_;
	static vector<B> cache_;
	// NOTE: p_ must be prime for this to work.
	static void cache(long long n) {
		cache_p_ = p_;
		cache_.assign(n + 1, 1);
		for(long long i = 2; i <= n; ++i) cache_[i] = mod(-(p_ / i) * cache_[p_ % i], p_);
	}
};
template <>
long long field<long long>::p_{1};
template <>
long long field<long long>::cache_p_{0};
template <>
vector<long long> field<long long>::cache_{};
template <>
__int128 field<__int128>::p_{1};
template <>
__int128 field<__int128>::cache_p_{0};
template <>
vector<__int128> field<__int128>::cache_{};

template <typename B>
field<B> pow(field<B> b, ll e) {
	using T = field<B>;
	T p     = e < 2 ? T{1, b.p} : pow(b * b, e / 2);
	return e & 1 ? p * b : p;
}

#include <iomanip>
#include <iostream>
#include <optional>
#include <utility>
#include <vector>
#include <map>
#include <set>

namespace std{
template <>
struct is_integral<__int128> : std::integral_constant<bool, true> {
};
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::optional<T> &v) {
	if(v)
		return o << *v;
	else
		return o << "{}";
}

std::ostream &operator<<(std::ostream &o, const __int128 &x) {
	if(x >= 1e18)
		return o << (long long)(x / (long long)1e18) << std::setw(18)
		         << (long long)((x < 0 ? -x : x) % (long long)1e18);
	else
		return o << (long long)x;
}
std::istream &operator>>(std::istream &o, __int128 &x) {
	std::string input;
	o >> input;
	if(input.size() > 18) {
		std::string high = input.substr(0, input.size() - 18);
		std::string low  = input.substr(input.size() - 18, input.size());
		__int128 highval = stoull(high);
		__int128 lowval  = stoull(low);
		x                = highval * (long long)1e18 + (highval < 0 ? -1 : 1) * lowval;
	} else {
		x = stoull(input);
	}
	return o;
}
std::ostream &operator<<(std::ostream &o, const unsigned __int128 &x) {
	if(x >= 1e18)
		return o << (long long)(x / (long long)1e18) << std::setw(18)
		         << (long long)(x % (long long)1e18);
	else
		return o << (long long)x;
}
std::istream &operator>>(std::istream &o, unsigned __int128 &x) {
	std::string input;
	o >> input;
	if(input.size() > 18) {
		std::string high = input.substr(0, input.size() - 18);
		std::string low  = input.substr(input.size() - 18, input.size());
		x = __int128(stoull(high)) * __int128((long long)1e18) + __int128(stoull(low));
	} else {
		x = stoull(input);
	}
	return o;
}

template <typename X, typename Y>
std::ostream &operator<<(std::ostream &o, const std::pair<X, Y> &p) {
	return o << '(' << p.first << ',' << p.second << ')';
}
template <typename X, typename Y, typename Z>
std::ostream &operator<<(std::ostream &o, const std::tuple<X, Y, Z> &p) {
	return o << '(' << get<0>(p) << ',' << get<1>(p) << ',' << get<2>(p) << ')';
}
template <typename X, typename Y>
std::istream &operator>>(std::istream &i, std::pair<X, Y> &p) {
	return i >> p.first >> p.second;
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &o, const std::array<T, N> &v) {
	for(auto &x : v) o << x << "\t";
	return o;
}
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> &v) {
	for(const auto &x : v) o << x << "\t";
	return o;
}
template <typename U, typename V>
std::ostream &operator<<(std::ostream &o, const std::map<U, V> &m) {
	for(const auto &[k, v] : m) o << k << "\t -> " << v << "\n";
	return o;
}
template <typename T>
std::ostream &operator<<(std::ostream &o, const std::set<T> &m) {
	for(const auto &k : m) o << k << "\n";
	return o;
}

#include <future>

void brinc(int& x, int k) {
	int i = k - 1, s = 1 << i;
	x ^= s;
	if((x & s) != s) {
		--i;
		s >>= 1;
		while(i >= 0 && ((x & s) == s)) x = x & ~s, --i, s >>= 1;
		if(i >= 0) x |= s;
	}
}

template <typename T>
void fft(vector<T>& A, int p, bool inv = false) {
	int N = 1 << p;
	for(int i = 0, r = 0; i < N; ++i, brinc(r, p))
		if(i < r) swap(A[i], A[r]);
	for(int m = 2; m <= N; m <<= 1) {
		T w, w_m = T::root(inv ? -m : m);
		for(int k = 0; k < N; k += m) {
			w = T{1};
			for(int j = 0; j < m / 2; ++j) {
				T t              = w * A[k + j + m / 2];
				A[k + j + m / 2] = A[k + j] - t;
				A[k + j]         = A[k + j] + t;
				w                = w * w_m;
			}
		}
	}
	if(inv) {
		T inverse = T(N).inv();
		for(auto& x : A) x = x * inverse;
	}
}

// convolution leaves A and B in frequency domain state.
template <typename T>
vector<T> convolution(vector<T>& A, vector<T>& B) {
	int s = A.size() + B.size() - 1;
	if(s == 1) return {A[0] * B[0]};
	int q = 32 - __builtin_clz(s - 1), N = 1 << q;
	A.resize(N, {});
	B.resize(N, {});
	fft(A, q, false);
	fft(B, q, false);
	vector<T> C(N);
	for(int i = 0; i < N; ++i) C[i] = A[i] * B[i];
	fft(C, q, true);
	C.resize(s);
	return C;
}

template <typename T>
void pow(vector<T>& A, long long e) {
	if(A.size() == 1) return A[0] = pow(A[0], e), void();
	int s = e * (A.size() - 1) + 1, q = 32 - __builtin_clz(s - 1), N = 1 << q;
	A.resize(N, {});
	fft(A, q, false);
	for(auto& x : A) x = pow(x, e);
	fft(A, q, true);
	A.resize(s);
}

// Solves x = ai mod mi. x is unique modulo lcm mi.
// Returns {0, -1} on failure, {x, lcm mi} otherwise.
template <typename T>
pair<T, T> crt(const vector<T>& a, const vector<T>& m) {
	pair<T, T> res = {a[0], m[0]};
	for(int i = 1; i < a.size(); ++i) {
		res = crt<T>(res.first, res.second, mod(a[i], m[i]), m[i]);
		if(res.second == -1) break;
	}
	return res;
}

template <typename T>
struct Poly;

template <auto M>
Poly<Field<M>> convolution(const Poly<Field<M>>& A, const Poly<Field<M>>& B) {
	auto convolution_base = [](const vector<Field<M>>& A, const vector<Field<M>>& B, auto f) {
		vector<decltype(f)> A2(A.size()), B2(B.size());
		// Make sure to use positive representations for all modulo values.
		for(int i = 0; i < A.size(); ++i) A2[i] = A[i].val();
		for(int i = 0; i < B.size(); ++i) B2[i] = B[i].val();
		return convolution(A2, B2);
	};

	auto H1 = async(launch::async, convolution_base, A, B, F1());
	auto H2 = async(launch::async, convolution_base, A, B, F2());
	auto H3 = async(launch::async, convolution_base, A, B, F3());
	auto C1 = H1.get();
	auto C2 = H2.get();
	auto C3 = H3.get();

	Poly<Field<M>> v(A.size() + B.size() - 1);
	for(int i = 0; i < v.size(); ++i)
		v[i] =
		    crt<__int128>({C1[i].val(), C2[i].val(), C3[i].val()}, {F1::p, F2::p, F3::p}).first % M;
	return v;
}

template <long long M>
Poly<Field<M>> fftpow(const Poly<Field<M>>& A, long long e) {
	// TODO: For larger exponents, we need more fields / in between steps.
	assert(e <= 2);

	auto pow_base = [](const vector<Field<M>>& A, long long e, auto f) {
		vector<decltype(f)> A2(A.size());
		for(int i = 0; i < A.size(); ++i) A2[i] = A[i].val();
		pow(A2, e);
		return A2;
	};

	auto H1 = async(launch::async, [&] { return pow_base(A, e, F1()); });
	auto H2 = async(launch::async, [&] { return pow_base(A, e, F2()); });
	auto H3 = async(launch::async, [&] { return pow_base(A, e, F3()); });
	auto C1 = H1.get();
	auto C2 = H2.get();
	auto C3 = H3.get();

	Poly<Field<M>> v(e * (A.size() - 1) + 1);
	for(int i = 0; i < v.size(); ++i)
		v[i] = crt<__int128>({C1[i].x, C2[i].x, C3[i].x}, {F1::p, F2::p, F3::p}).first % M;

	return v;
}

#include <algorithm>
#include <numeric>
using namespace std;
using F             = F1;
constexpr int FREE  = 128;
constexpr int BOUND = 28;
int main() {
	int n, m;
	cin >> n >> m;
	string line;
	getline(cin, line);
	map<string, int> ids;
	ids["?"]  = FREE;
	auto read = [&] {
		getline(cin, line);
		auto [it, ins] = ids.emplace(line, ids.size() - 1);
		return it->second;
	};
	vector<int> s(n), p(m);
	for(auto& x : s) x = read();
	for(auto& x : p) x = read();

	assert(ids.size() <= 1 + BOUND);

	vector<bool> pos(n - m + 1, true);
	for(int bit = 1; bit < BOUND; bit *= 2) {
		for(int negate : {0, 127}) {
			vector<F> string(n), pattern(m);
			for(int i = 0; i < n; ++i)
				string[i] = (s[i] == FREE or ((negate ^ s[i]) & bit)) ? 1 : 0;
			for(int i = 0; i < m; ++i)
				pattern[m - 1 - i] = (p[i] != FREE and ((negate ^ p[i]) & bit)) ? 1 : 0;
			int num_id = accumulate(begin(pattern), end(pattern), F(0)).val();

			auto conv = convolution(string, pattern);
			assert(conv.size() == n + m - 1);
			for(int i = 0; i < n - m + 1; ++i)
				if(conv[i + m - 1].val() != num_id) pos[i] = false;
		}
	}
	cout << accumulate(begin(pos), end(pos), 0) << endl;
}
