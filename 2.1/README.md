# racebench 2.1

このテストセットは単一変数アクセスシーケンスパターンのテストにのみ適用されます。

テストセットはシンプルテストセットと実際のプログラムテストセットの2つの部分に分けられます。実プログラムテストセットは商業秘密のため公開できません。競技会当日に提供され、参加者は自分の環境で即座にテストします。

*注：*

* *すべてのテストケースは標準C言語文法に準拠しています。*
* *テストケースは割り込みの周期性を考慮しません。割り込みは割り込みが許可されている場合にメインプログラムまたは低レベル割り込みを中断できます。中断のタイミング、位置、回数は不定です。*

## テストケースセット設定説明

* 割り込み番号はテストケースで提供される割り込み開閉関数に使用されます。enable_isr(n)とdisable_isr(n)はunlock/lock原語と見なせます。nは割り込み番号を表し、n=-1の場合はすべての割り込みをマスク/解除します。
* 優先度の数字が大きいほど優先度が高い

### シンプルテストセット

合計31個のテストケース。

| 序号 | テストケース名       | メインプログラム入口    | 割り込みハンドラ入口/割り込み番号/優先度                                       |
| ---- | -------------------- | ----------------------- | ------------------------------------------------------------ |
| 1    | svp_simple_001_001.c | svp_simple_001_001_main | svp_simple_001_001_isr_1/1/1   svp_simple_001_001_isr_2/2/2  |
| 2    | svp_simple_002_001.c | svp_simple_002_001_main | svp_simple_002_001_isr_1/1/1     svp_simple_002_001_isr_2/2/2 |
| 3    | svp_simple_003_001.c | svp_simple_003_001_main | svp_simple_003_001_isr_1/1/1     svp_simple_003_001_isr_2/2/2 |
| 4    | svp_simple_004_001.c | svp_simple_004_001_main | svp_simple_004_001_isr_1/1/1    svp_simple_004_001_isr_2/2/2 |
| 5    | svp_simple_005_001.c | svp_simple_005_001_main | svp_simple_005_001_isr_1/1/1                                 |
| 6    | svp_simple_006_001.c | svp_simple_006_001_main | svp_simple_006_001_isr_1/1/1                                 |
| 7    | svp_simple_007_001.c | svp_simple_007_001_main | svp_simple_007_001_isr_1/1/1                                 |
| 8    | svp_simple_008_001.c | svp_simple_008_001_main | svp_simple_008_001_isr_1/1/1                                 |
| 9    | svp_simple_009_001.c | svp_simple_009_001_main | svp_simple_009_001_isr_1/1/1                                 |
| 10   | svp_simple_010_001.c | svp_simple_010_001_main | svp_simple_010_001_isr_1/1/1                                 |
| 11   | svp_simple_011_001.c | svp_simple_011_001_main | svp_simple_011_001_isr_1/1/1                                 |
| 12   | svp_simple_012_001.c | svp_simple_012_001_main | svp_simple_012_001_isr_1/1/1                                 |
| 13   | svp_simple_013_001.c | svp_simple_013_001_main | svp_simple_013_001_isr_1/1/1  svp_simple_013_001_isr_2/2/2  svp_simple_013_001_isr_3/3/3 |
| 14   | svp_simple_014_001.c | svp_simple_014_001_main | svp_simple_014_001_isr_1/1/1    svp_simple_014_001_isr_2/2/2   svp_simple_014_001_isr_3/3/3 |
| 15   | svp_simple_015_001.c | svp_simple_015_001_main | svp_simple_015_001_isr_1/1/1                                 |
| 16   | svp_simple_016_001.c | svp_simple_016_001_main | svp_simple_016_001_isr_1/1/1                                 |
| 17   | svp_simple_017_001.c | svp_simple_017_001_main | svp_simple_017_001_isr_1/1/1                                 |
| 18   | svp_simple_018_001.c | svp_simple_018_001_main | svp_simple_018_001_isr_1/1/1  svp_simple_018_001_isr_2/2/2   |
| 19   | svp_simple_019_001.c | svp_simple_019_001_main | svp_simple_019_001_isr_1/1/1                                 |
| 20   | svp_simple_020_001.c | svp_simple_020_001_main | svp_simple_020_001_isr_1/1/1   svp_simple_020_001_isr_2/2/2  |
| 21   | svp_simple_021_001.c | svp_simple_021_001_main | svp_simple_021_001_isr_1/1/1                                 |
| 22   | svp_simple_022_001.c | svp_simple_022_001_main | svp_simple_022_001_isr_1/1/1                                 |
| 23   | svp_simple_023_001.c | svp_simple_023_001_main | svp_simple_023_001_isr_1/1/1                                 |
| 24   | svp_simple_024_001.c | svp_simple_024_001_main | svp_simple_024_001_isr_1/1/1                                 |
| 25   | svp_simple_025_001.c | svp_simple_025_001_main | svp_simple_025_001_isr_1/1/1                                 |
| 26   | svp_simple_026_001.c | svp_simple_026_001_main | svp_simple_026_001_isr_1/1/1     svp_simple_026_001_isr_2/2/2 |
| 27   | svp_simple_027_001.c | svp_simple_027_001_main | svp_simple_027_001_isr_1/1/1    svp_simple_027_001_isr_2/2/2    svp_simple_027_001_isr_3/3/3 |
| 28   | svp_simple_028_001.c | svp_simple_028_001_main | svp_simple_028_001_isr_1/1/1     svp_simple_028_001_isr_2/2/2    svp_simple_028_001_isr_3/3/3 |
| 29   | svp_simple_029_001.c | svp_simple_029_001_main | svp_simple_029_001_isr_1/1/1                                 |
| 30   | svp_simple_030_001.c | svp_simple_030_001_main | svp_simple_030_001_isr_1/1/1     svp_simple_030_001_isr_2/2/2  svp_simple_030_001_isr_3/3/3 |
| 31   | svp_simple_031_001.c | svp_simple_031_001_main | svp_simple_031_001_isr_1/1/1                                 |

### 実プログラムテストセット

合計2個のテストケース。

| 序号 | テストケース名 | メインプログラム入口 | 割り込みハンドラ入口/割り込み番号/優先度                                       |
| ---- | -------------- | ---------- | ------------------------------------------------------------ |
| 1    | svp_real_001.c | main       | CAN_ISR/1/1     TIMER_ISR/2/2                                |
| 2    | svp_real_002.c | main       | interrupt_low_0/1/1     interrupt_low_1/2/1     interrupt_high/3/2 |
