 # Windows

## 指令

``` 
# 查询端口
netstat -ano
# 查询指定端口
netstat -ano |findstr "端口号"
#根据进程PID查询进程名称
tasklist |ffindstr "进程PID号"
#根据PID杀死进程
taskkill -f -pid "进程pid号"
#根据进程名称杀死进程
taskkill -f -t -im "进程名称"
```



