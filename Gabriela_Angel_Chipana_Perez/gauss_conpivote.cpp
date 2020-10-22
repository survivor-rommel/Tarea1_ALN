#include <iostream>
#include <stdlib.h>

template <typename T>
void display(T** matrix, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size+1; j++)
            std::cout<< *(*(matrix+i)+j) << "  ";
        std::cout<<std::endl;
    }   
}

template <typename T>
void fill_in(T** matrix, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size+1; j++)
        {
            std::cout<< "Ingrese en la posicion: " << i << j <<std::endl;
            std::cin>>*(*(matrix+i)+j);
        }
    }   
}

template <typename T>
void swap(T** matrix, int size, int i)
{
    T tmp;
    for (int j=0; j<size+1;  j++)
    {
        tmp  = *(*(matrix+i)+j);
        *(*(matrix+i)+j) = *(*(matrix+0)+j);
        *(*(matrix+0)+j) = tmp;  
    }
}
template <typename T>
void Eliminacion_Gausiana_conPi(T** matrix, int size)
{
    //Reacomodar la matrix
    T max = 0;
    int j;
    for(int i = 0; i < size; i++)
    {
        if(  abs(*(*(matrix+i)+0)) > max)
        {
            max = *(*(matrix+i)+0);
            j = i;
        }    
    }
    swap(matrix, size, j);
    std::cout<<"Reacomodamos la Matrix" <<std::endl;
    display(matrix, size);

    int iterator = 0;
    while(iterator < size-1)
    {
        T second = *(*(matrix+iterator)+iterator);
        for(int f=iterator+1; f<size; f++)
        {
            T first = *(*(matrix+f)+iterator);
            std::cout<<"first: "<<first << " "<< "second: "<<second <<std::endl; 
            for(int i = 0; i<size+1; i++)
            {
                *(*(matrix+f)+i) = *(*(matrix+f)+i) - ( ( first * *(*(matrix+iterator)+i)) / second); 
            }
            std::cout<<"Volvemos..." <<std::endl;
            display(matrix, size);
        }
        ++iterator;
        std::cout<<"OK"<<std::endl;
    }
    //Despejamos variables
    std::cout<<"Vamos a despejar"<<std::endl;
    float* vector{new float[size]};
    for(int i=0; i<size; i++)
        vector[i] = 0;

    int iterat = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    for(int i=size-1; i>-1; i--)
    {
        for(iterat=0; iterat<size; iterat++)
        {
            vector[iterat] = vector[iterat] + *(*(matrix+i)+iterat) * vector[i];
        }
        vector[iterat] = ( *(*(matrix+i)+i+1) - (vector[iterat] - vector[j] * *(*(matrix+i)+i))) / *(*(matrix+i)+i) ;
        std::cout<<"Variable"<<i+1<<"= "<<vector[iterat]<<std::endl;
        iterat=0;
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

    delete vector;
    return;
}

int main()
{
    int size = 3;
    int** matrix {new int*[size]};
    for(int i = 0; i < size ; ++i)
    {
        matrix[i] = new int[size];
    }
    fill_in(matrix, size);
    display(matrix, size);
    std::cout<<"Eliminacion gausiana"<<std::endl;
    Eliminacion_Gausiana_conPi(matrix, size);
    for(int i = 0; i < size ; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
