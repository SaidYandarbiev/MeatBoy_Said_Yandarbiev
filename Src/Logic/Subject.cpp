//
// Created by said2 on 10-11-2022.
//

#include "Subject.h"
#include "Observer.h"

void Subject::Attach(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
    observer->Attach((std::shared_ptr<Subject>(this)));
}
