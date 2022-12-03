class Singleton {
	/*DOCS*/


	public:
		Singleton(const Singleton&)	 = delete;
		static Singleton& get;

	private:
		Singleton();
		static Singleton _instance;
};

Singleton Singleton::_instance;

Singleton::Singleton() {}

Singleton& Singleton::get() {
	return Singleton::_instance;
}