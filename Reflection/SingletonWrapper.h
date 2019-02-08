#ifndef SINGLETONWRAPPER_H
#define SINGLETONWRAPPER_H

template<typename Singleton>
class SingletonWrapper
{
public:
    SingletonWrapper(Singleton **s = nullptr);
    ~SingletonWrapper();
private:
    Singleton **S;
};

#endif // !SINGLETONWRAPPER_H

template<typename Singleton>
inline SingletonWrapper<Singleton>::SingletonWrapper(Singleton **s)
    :
    S(s)
{
}

template<typename Singleton>
inline SingletonWrapper<Singleton>::~SingletonWrapper(){
    if (*S) {
        delete *S;
    }
}
