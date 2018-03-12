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
int num_groups;
int flower_count;

int best;


void bruteforce(int state,int changes_left,int n_group,int bad){
    if(bad > best){
        return;
    }
    if(n_group == num_groups ) {

        if(best > bad){
            best = bad;
        }
        return;
    }
    if(state != groups[n_group].state){
        bad = bad + groups[n_group].size;
    }
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
    if(num_changes >= num_groups){
        return;
    }
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
    std::cout << best <<'\n';
}


void input(){
    std::string str;
    num_changes = 0;
    while(std::getline (std::cin,str)){
        groups.clear();
        num_changes = 0;
        num_groups = 0;
        flower_count = 0;
        int i;
        for(i = 0; i<(int)str.size();i++){
            if(str[i]!=' '){
                num_changes = 10*num_changes + ((int)str[i]-48);
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
        www();
    }
}


int main() {

    num_groups = 0;
    flower_count=0;
    input();

    return 0;
}