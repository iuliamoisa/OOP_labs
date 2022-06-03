#include "Parcare.h"


void Parcare::Create(int maxCapacity) {
	this->maxCapacity = maxCapacity;
}
bool Parcare::Add(Masina* a) {
    if (m.size() < maxCapacity)
    {
        m.push_back(a);
        return 1;
    }
    return 0;
}

void Parcare::RemoveByName(string name) {
    for (auto i = 0; i < m.size(); i++)
        if (m[i]->GetName() == name)
            m.erase(m.begin() + i);

}
int Parcare::GetCount() {
    return m.size();
}
bool Parcare::IsFull() {
    if (m.size() == maxCapacity)
        return 1;
    return 0;
}
void Parcare::ShowAll() {
    for (auto i = 0; i < m.size(); i++) {
        cout << m[i]->GetName() << "(" << m[i]->GetColor() << "),";
    }
}
void Parcare::ShowByColor(string color) {
    for (auto i = 0; i < m.size(); i++) {
        if (m[i]->GetColor() == color) {
            cout << m[i]->GetName() << ",";
        }
    }
}
