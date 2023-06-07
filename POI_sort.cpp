#include <iostream>
#include <vector>
#include <algorithm>

// POI 구조체 정의
struct POI {
    std::string name;
    // 다른 필요한 멤버 변수들...
};

// POI 이름을 한글 사전 순으로 비교하는 함수
bool comparePOI(const POI& poi1, const POI& poi2) {
    return poi1.name < poi2.name;
}

int main() {
    // POI 목록 생성
    std::vector<POI> poiList = {
        {"사당"},
        {"홍대"},
        {"강남"},
        // 다른 POI 명칭들 추가...
    };

    // POI 명칭 정렬
    std::sort(poiList.begin(), poiList.end(), comparePOI);

    // 정렬된 POI 목록 출력
    for (const POI& poi : poiList) {
        std::cout << poi.name << std::endl;
    }

    return 0;
}