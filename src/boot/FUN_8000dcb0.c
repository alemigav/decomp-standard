/* FUN_8000dcb0
 * image   boot (boot), base 0x80000480
 * address 0x8000dcb0  body 0x8000dcb0..0x8000dd63  size 180 B
 * body sha256 2666fc5888580aba6cd7ad0d14693599b1311edd316e26bb971557420e5d1667
 * provider record sha256 3ae9fff41cee530f98212a09563fef0fd0348e69c3133518e6728c468b53295c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000dcb0(int param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  
  uVar1 = FUN_800072e0();
  uVar2 = 4;
  if (param_1 != 0) {
    uVar2 = *(ushort *)(param_1 + 0x10);
  }
  if (uVar2 == 4) {
    *(undefined2 *)(_DAT_80012950 + 0x10) = 1;
    FUN_80000dd4(0);
  }
  else {
    if (uVar2 < 5) {
      if (uVar2 != 2) goto LAB_8000dd48;
    }
    else if (uVar2 != 8) goto LAB_8000dd48;
    *(undefined2 *)(param_1 + 0x10) = 1;
    FUN_8000ded0(*(undefined4 *)(param_1 + 8),param_1);
  }
LAB_8000dd48:
  FUN_80007300(uVar1);
  return;
}
