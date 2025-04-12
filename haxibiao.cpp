#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // 创建一个哈希表，键为string类型，值为int类型     unordered_mapC++标准库中基于哈希表实现的容器类型  hashmap：哈希表实例的名称hashmap：哈希表实例的名称
    //可以通过键访问值，不能通过值访问键，因为不同键可能对应同一个值。
    // unordered_set:
    // 用于存储一组无重复元素的集合。
    // 不存储键-值对，只存储独立的元素。[a,b,c,d,e,f,g](不保证顺序)
    // 适用于只需要判断某个值是否存在的情况，或者需要对值去重。
    // unordered_map:
    // 用于存储键-值对的映射。
    // 键是唯一的（无重复），值可以重复。[[a,1],[d,1],[b,2],[c,3]]（不保证顺序）
    // 适用于需要根据键快速查找对应的值的场景。
    // unordered_set<int> numSet(nums.begin(), nums.end());           存储类型为整形，只存储键，不存储值
    unordered_map<string, int> hashmap;

    // 1. 插入键值对
    hashmap["apple"] = 5;
    hashmap["banana"] = 10;
    hashmap["cherry"] = 20;

    // 2. 使用 insert 方法插入键值对
    hashmap.insert({"date", 15});

    // 3. 查找某个键对应的值
    string key = "banana";                 //1️⃣ 查找单词 banana → 2️⃣ 翻到字母B部分 → 3️⃣ 若找到单词就指向它，找不到则翻到空白页。 空白页作用：提示“查完了，后面没内容了”。
    if (hashmap.find(key) != hashmap.end()) {                  //这个情况说明在表中找到了对应的键，不等于边界结束位置，如果没找到对应的则等于边界位置，即end()。
        cout << "Key: " << key << ", Value: " << hashmap[key] << endl;
    } else {
        cout << "Key " << key << " not found!" << endl;
    }

    // 4. 遍历整个哈希表
    cout << "All elements in the hashmap:" << endl;
    for (const auto &pair : hashmap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // 5. 删除某个键值对
    hashmap.erase("apple");
    cout << "After removing 'apple':" << endl;
    for (const auto &pair : hashmap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // 6. 检查是否存在某个键
    key = "cherry";
    if (hashmap.count(key) > 0) {
        cout << "Key " << key << " exists in the hashmap." << endl;
    } else {
        cout << "Key " << key << " does not exist in the hashmap." << endl;
    }

    // 7. 更新某个键的值
    hashmap["banana"] = 25; // 更新键 "banana" 的值
    cout << "Updated value of 'banana': " << hashmap["banana"] << endl;

    return 0;
}
