选择文件
<img width="1794" height="1218" alt="image" src="https://github.com/user-attachments/assets/b2dd3a99-b2b2-41b9-8bb4-91674294564b" />
加载即可，目前为开发版，绘制卡顿是应为Timer节点触发了节点界面的重绘，把Timer节点删除即可，后续版本采用信号触发解决该问题
<img width="2559" height="1539" alt="image" src="https://github.com/user-attachments/assets/aec3694f-bb68-4383-b7c6-a93b82d9cc70" />
解决卡顿第二种方法，将此处的return删除让渲染窗口弹出，目前正在将渲染剥离到第二个Tab页，剥离完成后则无需弹出
<img width="2035" height="981" alt="image" src="https://github.com/user-attachments/assets/85235998-c982-4338-b3f8-408caf30a8d4" />
2025.8.21 渲染已和编辑剥离，实现了漫反射。light.flow

https://github.com/user-attachments/assets/19b79605-011f-49af-9c8d-9d5a418854ca

