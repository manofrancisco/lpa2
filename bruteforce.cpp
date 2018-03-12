//
// Created by Francisco Ferreira on 10/03/2018.
//

#include <iostream>
#include <vector>
class Group{
public:
    Group() {}
    int state;
    int size;
};

std::vector<Group> groups;

int num_changes;
int num_groups;

int start;
int row_count;
int flower_count;

int best;


void bruteforce(int state,int changes_left,int n_group,int bad){
    if(bad > best){
        return;
    }
    if(n_group == num_groups ) {

        if(best > bad){
            best = bad;
            std::cout<< "Resultado final: "<< bad << " Best: "<< best<<'\n';
        }
        return;
    }
    if(state != groups[n_group].state){
        bad = bad + groups[n_group].size;
    }
    std::cout<< "[" << n_group <<"] State: " << state << " Flores: " << groups[n_group].state << " Flores erradas: "<< bad<<'\n';
    bruteforce(state,changes_left,n_group+1,bad);

    if(changes_left) {
        if (state == 0)
            bruteforce(1, changes_left - 1, n_group + 1,bad);
        else
            bruteforce(0, changes_left - 1, n_group + 1,bad);

    }
}

void www(){
    best = 1501;
    num_groups = (int) groups.size();
    if(num_changes >= groups.size()){
        std::cout << 0;
        return;
    }
    std::cout << "\n\n" << groups.size() <<"\n\n";
    int state = 1;
    if(groups[0].state != state) {
        bruteforce(state, num_changes - 1, 1, groups[0].size);
    }else{
        bruteforce(state, num_changes - 1, 1, 0);
    }
    state = 0;
    if(groups[0].state != state) {
        bruteforce(state, num_changes - 1, 1, groups[0].size);
    }else{
        bruteforce(state, num_changes - 1, 1, 0);
    }
    std::cout << "Melhor possivel: " << best << "\n\n";
}


void input(){
    std::string str;
    num_changes = 0;
    while(std::getline (std::cin,str)){
        groups.clear();
        num_changes = 0;
        row_count = 0;
        flower_count = 0;
        std::cout << str <<"\n";
        int i;
        for(i = 0; i<str.size();i++){
            if(str[i]!=' '){
                num_changes = 10*num_changes + ((int)str[i]-48);
            }else break;
        }
        std::cout << "Numero de trocas permitidas: " << num_changes << "\n";
        int counter = 1;
        int state = str[i+1]-48;
        start = state;
        for(i= i+2;i<str.size();i++){
            if(((int)str[i]-48) != state){
                Group r;
                r.size = counter;
                r.state = state;
                groups.push_back(r);
                std::cout << "Linha de tulipas num:" << state << " com "<< counter << "flores  \n";
                row_count++;
                state = (int)str[i]-48;
                counter = 1;
            }else{
                counter++;
            }
            flower_count++;
        }
        Group r;
        r.size = counter;
        r.state = state;
        groups.push_back(r);
        row_count++;
        std::cout << "Linha de tulipas num:" << state << " com "<< counter << "flores  \n";
        std::cout << " Numero total de linhas: " << row_count <<"\n Numero total de flores: "<<flower_count<<"\n";
        www();
    }
}


int main() {

    std::cout << "Hello, World!" << std::endl;
    row_count = 0;
    flower_count=0;
    input();

    return 0;
}