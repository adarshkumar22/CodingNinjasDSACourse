template <typename T>
class queue_using_array
{
    T *data;
    int size;
    int nextIndex;
    int firstIndex;
    int capacity;

public:
    queue_using_array(int s) {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }
    int get_size() {
        return size;
    }
    bool is_empty() {
        return size == 0;
    }
    //insert element
    void enqueue(T element) {
        if(size == capacity) {
            // cout<<"Queue Full!"<<endl;
            // return;
            T *newData = new T[2*capacity];
            int j = 0;
            for(int i = firstIndex; i<capacity; i++) {
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i<firstIndex; i++) {
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        if(firstIndex == -1) {
            firstIndex = 0;
        }        
        size++;
    }
    T front() {
        if(is_empty()) {
            cout<<"Queue Full!"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue() {
        if(is_empty()) {
            cout<<"Queue Full!"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};