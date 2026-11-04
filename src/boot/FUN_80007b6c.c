/* FUN_80007b6c
 * image   boot (boot), base 0x80000480
 * address 0x80007b6c  body 0x80007b6c..0x80007c1f  size 180 B
 * body sha256 164ce66c6f4ad364acbe58ea61986e80ee508529c0f44ed3b0feff3cf5a12ed0
 * provider record sha256 e5a0128923171078aed6f42d218cf318703696a3a258f8088ef6d753a0dd2057
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80007b6c(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = _DAT_80017770;
  if (_DAT_80017770 != (undefined4 *)0x0) {
    iVar4 = _DAT_80017770[4];
    if ((int)_DAT_80017770[2] < iVar4) {
      iVar2 = _DAT_80017770[3] + _DAT_80017770[2];
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar2 == -0x80000000)) {
        trap(0x1800);
      }
      *(undefined4 *)((iVar2 % iVar4) * 4 + _DAT_80017770[5]) = _DAT_80017774;
      puVar1[2] = puVar1[2] + 1;
      if (*(int *)*puVar1 != 0) {
        uVar3 = FUN_80000f50(puVar1);
        FUN_80000f08(&DAT_80012948,uVar3);
      }
    }
  }
  return;
}
