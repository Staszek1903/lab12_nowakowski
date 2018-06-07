#include "lineargenerator.h"

LinearGenerator::LinearGenerator(int xmax, int seed)
    :xmax(xmax), modullo(xmax + 1)
{
    c = choose_c();
    a = choose_a();
    xn = ((seed<0)?0:seed)%modullo;

//    std::cout<<"a: "<<a<<" xn: "<<xn<<" c: "<<c<<" modullo: "<<modullo<<std::endl;
}

int LinearGenerator::getRandom()
{
    xn = (a * xn + c) % modullo;
    return xn;
}

int LinearGenerator::choose_c()
{
    auto primes = prime_factors(modullo);

//    std::cout<<"primes: ";
//    for(int a: primes)
//        std::cout<<a<<std::endl;
//    std::cout<<std::endl;

    int candidate =2;

    while (true) {
        if(is_prime(candidate) && !is_inside(primes, candidate))
            break;
        ++candidate;
    }

    return candidate;
}

int LinearGenerator::choose_a()
{
    std::vector <std::pair <int, int > > lambdas, candidates;

    for(int a =2; a<modullo; ++a){
        int lambda = 1;

        while(1){
            long long pow = std::pow(a,lambda);
//            std::cout<<"pow a^lambda: "<<a<<"^"<<lambda<<"="<<pow<<"    modulo: "<<pow%modullo<<std::endl;
//            int temp;
//            std::cin>>temp;
            if(pow%modullo == 1)
                break;
            ++lambda;
            if(lambda > modullo){
                lambda = -1;
                break;
            }
        }

       lambdas.push_back(std::make_pair(a, lambda));

    }

//    for(auto pair: lambdas)
//        std::cout<<pair.first<<" "<<pair.second<<std::endl;


    int max_lambda = 0;
    for(auto pair: lambdas)
        if(pair.second > max_lambda)
            max_lambda = pair.second;

    for(auto pair: lambdas)
        if(pair.second == max_lambda)
            candidates.push_back(pair);

    int max_a = 0;
    for(auto pair: candidates)
        if(pair.first > max_a)
            max_a = pair.first;

    return max_a;
}

std::vector<int> prime_factors(int number)
{
    std::vector <int> result;

    int prime = 2;
    while (number > 1) {
        while (!(number%prime)) {
            result.push_back(prime);
            number/=prime;
        }

        ++prime;
    }

    return result;
}

bool is_prime(int number)
{
    int max = sqrt(number);

    for (int i= 2; i<max; ++i)
        if(!(number%i))
            return false;

    return true;
}

bool is_inside(std::vector<int> vector, int number)
{
    for(int a: vector)
        if(a == number)
            return true;
    return false;
}
