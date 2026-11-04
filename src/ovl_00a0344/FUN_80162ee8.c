/* FUN_80162ee8
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162ee8  body 0x80162ee8..0x80162feb  size 260 B
 * body sha256 216553b0f7bf1dccf684ab89f55a31bee582c2ea7052358aac2c8a61d61a26c0
 * provider record sha256 4c9d33cdb94af9fab5518691d987dac5ac605af292ade842e939ee52e9b9364f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162ee8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  ushort uVar6;
  int iVar4;
  uint uVar5;
  
  iVar3 = *(int *)(param_1 + 0x250);
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if ((bVar1 == 2) && (iVar4 = func_0x80089d54(param_1,param_2,param_3,0x200), iVar4 != 0)) {
        *(undefined1 *)(param_1 + 7) = 0;
      }
      goto LAB_80162f8c;
    }
    if (bVar1 != 0) goto LAB_80162f8c;
    *(undefined1 *)(param_1 + 7) = 1;
    uVar6 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar6 & 0x1f) + 0x1e;
  }
  sVar2 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x33c0700;
  }
LAB_80162f8c:
  if (*(char *)(iVar3 + 0x2b4) == '\0') {
    uVar5 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  if ((uVar5 < 1000) && (*(char *)(param_1 + 0x2be) == '\0')) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}
