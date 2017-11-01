#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class RAMSimulator{
public:
    RAMSimulator(){
        this->program_counter = 1;
    }

    void ReadFileToVector(const std::string &fileName){
        std::ifstream file(fileName);
        std::string line;

        if(file.is_open()){
            //copy the content in a string then push it in a vector...
            while(getline(file, line)){
                this->program_memory.push_back(line);
            }
            file.close();
        }else{
            std::cout<<"couldn't open file" << std::endl;
        }
    }

    void simulate(){
        while(this->program_counter <= program_memory.size()){
            std::string curr_instruction = program_memory[program_counter-1];
            //split command in string and value in a string
            std::string command = curr_instruction.substr(0, 3);
            std::string value = curr_instruction.substr(4, curr_instruction.size());

            choose_Instruction(command, value);

            program_counter++;
        }
    }

    void choose_Instruction(const std::string &command, const std::string &value){
        if(command == "INP"){
            INP(value);
        }else if(command == "LDK"){
            LDK(value);
        }else if(command == "STA"){
            STA(value);
        }else if(command == "LDA"){
            LDA(value);
        }else if(command == "MUL"){
            MUL(value);
        }else if(command == "ADD"){
            ADD(value);
        }else if(command == "SUB"){
            SUB(value);
        }else if(command == "JNE"){
            JNE(value);
        }else if(command == "OUT"){
            OUT(value);
        }else if(command == "HLT"){
            HLT(value);
        }else if(command == "DIV"){
            DIV(value);
        }else if(command == "JMP"){
            JMP(value);
        }else if(command == "JEZ"){
            JEZ(value);
        }else if(command == "JLZ"){
            JLZ(value);
        }else if(command == "JLE"){
            JLE(value);
        }else if(command == "JGZ"){
            JGZ(value);
        }else if(command == "JGE"){
            JGE(value);
        }
    }

    void INP(const std::string &value){
        std::cout <<"Enter a number" << std::endl;
        std::cin >> data_memory[value];
    }

    void LDK(const std::string &value){
        this->akkumulator = stoi(value);
    }

    void STA(const std::string &value){
        data_memory[value] = this->akkumulator;
    }

    void LDA(const std::string &value){
        this->akkumulator = data_memory[value];
    }

    void MUL(const std::string &value){
        this->akkumulator = this->akkumulator * data_memory[value];
    }

    void ADD(const std::string &value){
        this->akkumulator = this->akkumulator + data_memory[value];
    }

    void SUB(const std::string &value){
        this->akkumulator = this->akkumulator - data_memory[value];
    }

    void JNE(const std::string &value){
        if(this->akkumulator != 0){
            //to avoid the increasement of the program counter in the while loop
            program_counter = stoi(value)-1;
        }
    }

    void OUT(const std::string &value){
        std::cout << data_memory[value];
    }

    void HLT(const std::string &value){
        exit(stoi(value));
    }

    void DIV(const std::string &value){
        this->akkumulator = this->akkumulator / data_memory[value];
    }

    void JMP(const std::string &value){
        //to avoid the increasement of the program counter in the while loop
        program_counter = stoi(value)-1;
    }

    void JEZ(const std::string &value){
        if(this->akkumulator == 0){
            //to avoid the increasement of the program counter in the while loop
            program_counter = stoi(value)-1;
        }
    }

    void JLZ(const std::string &value){
        if(this->akkumulator < 0){
            //to avoid the increasement of the program counter in the while loop
            program_counter = stoi(value)-1;
        }
    }

    void JLE(const std::string &value){
        if(this->akkumulator <= 0){
            //to avoid the increasement of the program counter in the while loop
            program_counter = stoi(value)-1;
        }
    }

    void JGZ(const std::string &value){
        if(this->akkumulator > 0){
            //to avoid the increasement of the program counter in the while loop
            program_counter = stoi(value)-1;
        }
    }

    void JGE(const std::string &value){
        if(this->akkumulator >= 0){
            //to avoid the increasement of the program counter in the while loop
            program_counter = stoi(value)-1;
        }
    }

private:
    std::vector <std::string> program_memory;
    int akkumulator = 0;
    int program_counter;
    std::map <std::string, int> data_memory;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "There is no File attached" << std::endl;
    }

    RAMSimulator ramSimulator;

    ramSimulator.ReadFileToVector(argv[1]);

    ramSimulator.simulate();

    return 0;
}