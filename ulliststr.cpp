#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  // If the list is empty, add a new Item and initialize the value, first, and last. Point the tail_ to the head_.
  if (empty()){
    head_ = new Item;
    head_->next = nullptr;
    head_->val[head_->first] = val;
    head_->last++;
    tail_ = head_;
  }
  // If there is still room in the array, add the value to the end
  else if (tail_ -> last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  // If there is no more room in the array, add a new node to the end and store the value in the array.
  else{
    Item *temp = new Item;
    temp->val[temp->first] = val;
    temp->last++;
    temp->next = nullptr;
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
  }
  // Increment the size of the extended array
  size_++;
}

void ULListStr::pop_back(){
  // only pop back if there is something in the array/list
  if (!empty()){
    // move the index of the last position and decrement the size
    tail_->last--;
    size_--;
    // if there are no more values in the last array, delete the entire node
    if (tail_ -> last - tail_ -> first <= 0){
      Item *temp = tail_;
      tail_ = tail_->prev;
      if (tail_ != nullptr){
        tail_->next = nullptr;
      }
      else{
        head_ = nullptr;
      }
      delete temp;
    }
  }
}

void ULListStr::push_front(const std::string& val){
  // If the list is empty, add a new Item and initialize the value, first, and last. Point the tail_ to the head_.
  if(empty()){
    head_ = new Item;
    head_->next = nullptr;
    head_->val[head_->first] = val;
    head_->last++;
    tail_ = head_;
  }
  // If there is still room in the array, add the value to the front
  else if (head_ -> first > 0){
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
  // If there is no more room in the array, add a new node to the front and store the value in the array.
  else {
    Item *temp = new Item;
    temp->val[ARRSIZE-1] = val;
    temp->last = ARRSIZE;
    temp->first= ARRSIZE-1;
    temp->next = head_;
    temp->prev = nullptr;
    head_->prev = temp;
    head_ = head_->prev;
  }
  // Increment the size of the extended array
  size_++;
}

void ULListStr::pop_front(){
  // only pop front if there is something in the array/list
  if (!empty()){
    // move the index of the first position and decrement the size
    head_->first++;
    size_--;
    // if there are no more values in the first array, delete the entire node
    if (head_ -> last - head_ -> first <= 0){
      Item *temp = head_;
      head_ = head_->next;
      if (head_ != nullptr){
        head_->prev = nullptr;
      }
      else{
        tail_ = nullptr;
      }
      delete temp;
    }
  }
}

std::string const & ULListStr::back() const{
  // return the last element of the array in the tail
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  // return the first element of the array in the head
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  // check if loc is valid
  if (loc>=0 && loc<size()){
    // store the head in a temp variable to loop through the nodes
    Item *temp = head_;
    while (temp!=NULL){
      // check if the loc can be found in the node, return the loc if it is found in the node 
      size_t arraySize = temp->last - temp->first;
      if(arraySize > loc){
        return &(temp->val[temp->first + loc]);
      }
      // if not, move to the next node and adjust the loc
      temp = temp->next;
      loc -= arraySize;
    }
  }
  // loc is not valid or not found, returns null
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}