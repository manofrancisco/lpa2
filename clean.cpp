#include <iostream>
#include <vector>
 class Group{
 public:
     Group() {}
     int state;
     int size;
 };

std::vector<Group> groups;

std::vector<std::vector<std::vector<int> > > matrix;



std::vector<std::vector<std::vector<int> > > initialize_matrix(int num_groups,int max_changes){
    std::vector <int> change_vec((unsigned long)max_changes+1);
    for(int i = 0; i < max_changes;i++){
        change_vec[i] = 1501;
    }
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

int fertilize(int state,int n_group,int n_changes,int num_groups,int max_changes,std::vector<std::vector<std::vector<int> > >* m){
    if((*m)[state][n_group][n_changes] != 1501){
        return (*m)[state][n_group][n_changes];
    }
    Group current = groups[n_group];
    if(n_group == num_groups -1){

        if(current.state == state){
            (*m)[state][n_group][n_changes] = 0;
        }else{
            (*m)[state][n_group][n_changes] = current.size;
        }
        return (*m)[state][n_group][n_changes];
    }else{

        int wrong = ((state == current.state)? 0:current.size);
        int no_change = fertilize(state,n_group+1,n_changes,num_groups,max_changes,m);
        int change = 1501;
        if(n_changes < max_changes && current.state != groups[n_group+1].state){
            int new_state = ((current.state == 0)? 1:0);
            change = fertilize(new_state,n_group+1,n_changes+1,num_groups,max_changes,m);
        }else{
        }
        (*m)[state][n_group][n_changes] = wrong + ((change > no_change)? no_change:change);

        return (*m)[state][n_group][n_changes];
    }
}


int www(int num_groups,int max_changes){
    if(max_changes >= num_groups){
        return 0;
    }
    matrix = initialize_matrix(num_groups,max_changes);
    int start_1, start_2,new_state;
    Group first = groups[0];
    start_1 = fertilize(first.state,0,1,num_groups,max_changes,&matrix);
    new_state = ((first.state == 1)? 0:1);

    start_2 = fertilize(new_state,0,1,num_groups,max_changes,&matrix);
    return ((start_1 < start_2)? start_1: start_2);
}


void input(){
    std::string str;
    int  max_changes,num_groups;
    int best;
    while(std::getline (std::cin,str)){
        groups.clear();
        max_changes = 0;
        num_groups = 0;
        int i;
        for(i = 0; i<(int)str.size();i++){
            if(str[i]!=' '){
                max_changes = 10*max_changes + ((int)str[i]-48);
            }else break;
        }
        int counter = 1;
        int state = str[i+1]-48;
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
        }
        Group r;
        r.size = counter;
        r.state = state;
        groups.push_back(r);
        num_groups++;
        best = www(num_groups,max_changes);
        std::cout << best << '\n';
    }
}


int main() {

    input();

    return 0;
}