//
// Created by imd on 10/19/2018.
//

template<typename T>
class SmallVectorTemplateCommon {
protected:
    void setEnd(T *P);
};


template<typename T>
class SmallVectorImpl : public SmallVectorTemplateCommon<T> {
public:
    void push_back(const T &value) {
        // ...
        setEnd(this->end() + 1);
    }
};
