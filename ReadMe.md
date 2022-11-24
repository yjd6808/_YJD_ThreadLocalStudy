## 구글 벤치마크 비주얼 스튜디오 프로젝트 템플릿

비주얼 스튜디오만 설치되어있으면 
편하게 구글 벤치마크 사용가능

### 사용 방법

1. 프로젝트 이름은 알아서 변경 
   => project_name, project_name.vsxporj 이런 파일들 이름 수동으로 변경해줘야함

2. scripts/build_benchmark.bat 실행
3. 코딩 시작

<br>
<br>

### 기존 비주얼 스튜디오 프로젝트와 다른점
1. 프로젝트 필터 src, include 추가
1. 프로젝트 디렉토리에도 src, include 디렉토리 추가해줌
1. 프로젝트 속성 -> 일반 -> 출력 디렉토리: $(SolutionDir)out\$(Platform)\$(Configuration)\
1. 프로젝트 속성 -> 일반 -> 중간 디렉토리: $(SolutionDir)intermediate\$(Platform)\$(Configuration)\
1. 프로젝트 속성 -> 일반 -> C++ 표준: C++ 20
1. 프로젝트 속성 -> 고급 -> 문자셋: 멀티바이트
1. 프로젝트 속성 -> C/C++ -> 전처리기 -> BENCHMARK_STATIC_DEFINE 추가
1. 프로젝트 속성 -> C/C++ -> 명령줄 -> /source-charset:utf8
1. 프로젝트 속성 -> 링커 -> 입력 ->   
```
    shlwapi.lib  
    ws2_32.lib  
    benchmark.lib  
    benchmark_main.lib  
```
