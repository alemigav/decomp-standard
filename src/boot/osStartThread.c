/* osStartThread
 * image   boot (boot), base 0x80000480
 * address 0x8000db90  body 0x8000db90..0x8000dca7  size 280 B
 * body sha256 45e65129e2757bfe627f4c760debb6a76faa7820103ca72b91e70ecda43383e7
 * provider record sha256 16d34030daf8070eaa299faa85125f544a461ac7c761db40b71418f5635da9be
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void osStartThread(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  if (*(short *)(param_1 + 0x10) == 1) {
    if ((*(undefined1 **)(param_1 + 8) == (undefined1 *)0x0) ||
       (*(undefined1 **)(param_1 + 8) == &DAT_80012948)) {
      *(undefined2 *)(param_1 + 0x10) = 2;
    }
    else {
      *(undefined2 *)(param_1 + 0x10) = 8;
      FUN_80000f08(*(undefined4 *)(param_1 + 8),param_1);
      param_1 = FUN_80000f50(*(undefined4 *)(param_1 + 8));
    }
  }
  else {
    if (*(short *)(param_1 + 0x10) != 8) goto LAB_8000dc3c;
    *(undefined2 *)(param_1 + 0x10) = 2;
  }
  FUN_80000f08(&DAT_80012948,param_1);
LAB_8000dc3c:
  if (_DAT_80012950 == 0) {
    FUN_80000f60();
  }
  else if (*(int *)(_DAT_80012950 + 4) < *(int *)(_DAT_80012948 + 4)) {
    *(undefined2 *)(_DAT_80012950 + 0x10) = 2;
    FUN_80000dd4(&DAT_80012948);
  }
  FUN_80007300(uVar1);
  return;
}
