#include <iostream>
#include <vector>
class Group{
public:
    Group() {}
    int state;
    int size;
};

std::vector<Group> groups;

int max_changes;
int num_groups;

int start;
int flower_count;

int best;


std::vector<std::vector<std::vector<int> > > initialize_matrix(){
    std::vector <int> change_vec((unsigned long)max_changes+1);
    std::vector < std::vector <int> > group_vec((unsigned long)num_groups,change_vec);
    std::vector<std::vector<std::vector<int> > >m((unsigned long) 2,group_vec);



    for(int i = 0;i < 2;i++){
        for(int j = 0; j < num_groups;j++){
            for(int k = 0; k < max_changes+1;k++){
                m[i][j][k] = 1501;
            }
        }
    }
    return m;
}

int fertilize(int state,int n_group,int n_changes,std::vector<std::vector<std::vector<int> > > m){
    if(m[state][n_group][n_changes] != 1501){
        return m[state][n_group][n_changes];
    }
    Group current = groups[n_group];
    if(n_group == num_groups -1){

        if(current.state == state){
            m[state][n_group][n_changes] = 0;
        }else{
            m[state][n_group][n_changes] = current.size;
        }
        return m[state][n_group][n_changes];
    }else{

        int wrong = ((state == current.state)? 0:current.size);
        int no_change = fertilize(state,n_group+1,n_changes,m);
        int change = 1501;
        if(n_changes < max_changes && state != current.state){
            int new_state = ((current.state == 0)? 1:0);
            change = fertilize(new_state,n_group+1,n_changes+1,m);
        }
        m[state][n_group][n_changes] = wrong + ((change > no_change)? no_change:change);
        return m[state][n_group][n_changes];
    }
}


int www(){
    best = 1501;
    if(max_changes >= num_groups){
        return 0;
    }
    std::vector<std::vector<std::vector<int> > > m;
    m = initialize_matrix();
    int start_1, start_2,new_state;
    Group first = groups[0];
    start_1 = fertilize(first.state,1,1,m);
    new_state = ((first.state == 1)? 0:1);
    start_2 = first.size + fertilize(new_state,1,1,m);
    return ((start_1 < start_2)? start_1: start_2);
}


void input(){
    std::string str;
    max_changes = 0;
    while(std::getline (std::cin,str)){
        groups.clear();
        max_changes = 0;
        num_groups = 0;
        flower_count = 0;
        int i;
        for(i = 0; i<(int)str.size();i++){
            if(str[i]!=' '){
                max_changes = 10*max_changes + ((int)str[i]-48);
            }else break;
        }
        int counter = 1;
        int state = str[i+1]-48;
        start = state;
        for(i= i+2;i<(int)str.size();i++){
            if(((int)str[i]-48) != state){
                Group r;
                r.size = counter;
                r.state = state;
                groups.push_back(r);
                num_groups++;
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
        num_groups++;
        int best = www();
        std::cout << best << '\n';
    }
}


int main() {

    num_groups = 0;
    flower_count=0;
    input();

    return 0;
}