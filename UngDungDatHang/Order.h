#pragma once
#include <string>
#include <ctime>
#include <vector>
#include <iostream>
#include "CartItem.h"
#include "SanPham.h"
using namespace std;
class Order {
    private:
        string orderId;
        tm orderDate ;
        tm estimatedDeliveryDate;
        vector <CartItem> orderItems;
        double shippingFee;
        double totalAmount;
        string status;
    public:
        Order (string id, tm od, tm estimate, vector<CartItem> item, double fee, double sum)
        : orderId(id), orderDate(od), estimatedDeliveryDate(estimate), orderItems(item), shippingFee(fee),
        totalAmount(sum), status("Cho xac nhan"){
            calculateEstimatedDeliveryDate();
        } 
        double calculateShippingFee()// cho phi giao hang = 10% tong don hang
        {
           shippingFee =  0.1 *  totalAmount;
           return shippingFee;
        }
        double calculateTotalAmount(){
            totalAmount = 0;
            for (CartItem& item : orderItems){
                totalAmount += item.calculateSubTotal();
            }
            totalAmount += shippingFee;
            return totalAmount;
        };
        void confirmOrder(){
            status = "Dang giao";
            for (CartItem& item : orderItems){
                SanPham product = item;
                double newQuantity = product.getSoLuongTon() - item.getQuantity();
                product.updateSoLuongTon(newQuantity);
            }
        };
         void calculateEstimatedDeliveryDate(){
            estimatedDeliveryDate.tm_mday = orderDate.tm_mday + 3;
            mktime(&estimatedDeliveryDate);
        };
         void completeOrder(){
            if (status == "Dang giao" && estimatedDeliveryDate.tm_mday == orderDate.tm_mday + 3){
                status = "Da giao don hang thanh cong";
            }
        };
        string getStatus() {return status;};
        void displayOrderDetails(){
            cout << "Ma san pham: " << orderId;
            cout << "Ngay dat hang: " << asctime(&orderDate);
            cout << "Trang thai don hang: " << status <<endl;
            cout << "Thong tin ve san pham trong don hang:" << endl;
            for (CartItem& item : orderItems){
                item.displayInfo();
            }
            cout << "Tong so tien cua don hang: " << totalAmount << endl;
        };


};