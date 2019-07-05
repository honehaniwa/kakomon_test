# 筑波大学H25情報基礎

## 大問4

### 問題1

関数の中身を問う問題。 <br>
f4の <br>

```

if(y%2==1)
```

の部分は最後にy=1に必ずなるので注意が必要(筆者が間違えただけです)<br>

<br>

### 問題2

呼び出し回数を聞く問題。<br>
よく見るとy回呼び出されているだけです。<br>

<br>

### 問題3

(2)と同じく呼び出し回数の一般解を求める問題。<br>
f2の変数yにf3のxが代入されているところに注意すること。 <br>

### 問題4

(2)(3)と同じような内容。 <br>
再帰的にy/2をしていくと必ず1を通ることを忘れない!!!! <br>

### 問題5
穴埋め。 <br>
rがそのままf1のrと同じ意味なのでreturn rは確定、 <br>
あとはyを減らしながら再起をしてrにyを足していくだけ <br>
f5はrを初期化してgを呼び出すだけなのでrに0を入れればおしまい <br>

### 問題6
(5)と同じく再起関数を作る問題。 <br>
ただ、今回は値を保持するrを持っていないのでreturnするところに <br>
そのままrを持っておく必要がある。 <br>
rを更新するのは(y/2 == 1)のときのみなので <br>
(カ)でxを足してf6を再帰する必要がある。 <br>

### 大問4解答
```txt
問1
(A) 〇 (B) × (C) 〇 (D) 〇

問2
5回

問3
x * y

問4
文2 -> 2回
文3 -> 6回

問5
(ア) d (イ) i (ウ) f (エ) a

問6
オ -> 0
カ -> x+f6(x*2, y/2)
キ -> x*2
ク -> y/2
```