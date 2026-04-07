class Robot {
    string direction;
    vector<int> position;
    int w;
    int h;
public:
    Robot(int width, int height) {
        w = width-1;
        h = height-1;
        position.push_back(0);
        position.push_back(0);
        direction = "East";
    }
    
    void step(int num) {
        if(position[0] == 0 && position[1] == 0 && num >= 2*(h+w)){
            int val = 2*(h+w);
            if(num%val == 0) {
                direction = "South";
                step(num%val);
            }
            else step(num%val);
        }
        else if(direction == "East"){
            if(position[0] + num > w){
                direction = "North";
                int val = position[0];
                position[0] = w;
                step((val+num) - w);
            }else {
                position[0] = position[0] + num;
            }
        }
        else if(direction == "West"){
            if(position[0] - num < 0){
                direction = "South";
                int val = position[0];
                position[0] = 0;
                step(num-val);
            }else {
                position[0] = position[0] - num;
            }
        }
        else if(direction == "North"){
            if(position[1] + num > h){
                direction = "West";
                int val = position[1];
                position[1] = h;
                step((val + num) - h);
            }else {
                position[1] = position[1] + num;
            }
        }
        else{
            if(position[1] - num < 0){
                direction = "East";
                int val = position[1];
                position[1] = 0;
                step(num-val);
            }else {
                position[1] = position[1] - num;
            }
        }
    }
    
    vector<int> getPos() {
        return position;
    }
    
    string getDir() {
        return direction;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */