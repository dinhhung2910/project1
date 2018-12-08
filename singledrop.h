#ifndef DATATYPE_H
#define DATATYPE_H

/**
 * @brief The singleDrop struct
 * Cấu trúc lưu thông tin về 1 hạt mực
 * @param x Hoành độ
 * @param y Tung độ
 * @param speed Tốc độ giọt mực, tính theo pixel/s
 * @param direction Hướng di chuyển của giọt mực, đo bằng radian
 * @param stepX. stepY 1 bước di chuyển của giọt mực sau mỗi lần cập nhật
 * @param alarm khi alảm = 0, hướng di chuyển sẽ thay đổi
 * @param isActive Hạt có còn nằm trong mặt nước hay không
 */
struct SingleDrop {
    float x;
    float y;
    float speed;
    float direction;
    float stepX, stepY;
    int alarm;
    bool isActive;
};

#endif // DATATYPE_H
