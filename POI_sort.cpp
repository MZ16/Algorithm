#include <iostream>
#include <vector>
#include <algorithm>

// POI ����ü ����
struct POI {
    std::string name;
    // �ٸ� �ʿ��� ��� ������...
};

// POI �̸��� �ѱ� ���� ������ ���ϴ� �Լ�
bool comparePOI(const POI& poi1, const POI& poi2) {
    return poi1.name < poi2.name;
}

int main() {
    // POI ��� ����
    std::vector<POI> poiList = {
        {"���"},
        {"ȫ��"},
        {"����"},
        // �ٸ� POI ��Ī�� �߰�...
    };

    // POI ��Ī ����
    std::sort(poiList.begin(), poiList.end(), comparePOI);

    // ���ĵ� POI ��� ���
    for (const POI& poi : poiList) {
        std::cout << poi.name << std::endl;
    }

    return 0;
}