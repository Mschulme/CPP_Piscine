#include "Serializer.hpp"

int main(void)
{
    Data    DataStructure;
    DataStructure.identifier = 69420;
    DataStructure.name = "42_Wolfsburg";

    std::cout << "DataStructure.identifier == " << DataStructure.identifier << std::endl;
    std::cout << "DataStructure.name == " << DataStructure.name << std::endl;

    uintptr_t raw = Serializer::serialize(&DataStructure);
    std::cout << "Serialized Data pointer: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    if (deserializedData == &DataStructure)
    {
        std::cout << "Deserialaztion succesful." << std::endl; 
        std::cout << "Deserialsed Data - identifier: " << deserializedData->identifier << ", name: " << deserializedData->name << std::endl;
    }
    else
    {
        std::cout << "Deserialaztion failed." << std::endl;
    }

    return (EXIT_SUCCESS);
}