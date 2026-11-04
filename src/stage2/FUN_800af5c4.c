/* FUN_800af5c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af5c4  body 0x800af5c4..0x800af6ff  size 316 B
 * body sha256 7e84941e25d0ba028f40125b48461b612ee6c988e3d147681398e6b3fccdcd56
 * provider record sha256 4c76e91f8eef63f6e53bd01feb466f4f4de90cfceda3865c9499833d865b38f1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800af5c4(int param_1,uint *param_2)

{
  short sVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  uint uVar5;
  
  if (*param_2 >> 0x18 == 0) {
    sVar1 = *(short *)(param_1 + 0x50);
  }
  else {
    sVar1 = *(short *)(param_1 + 0x4e);
  }
  *(short *)(param_1 + 0x50) = sVar1 + (char)(*param_2 >> 8);
  if (*(short *)(param_1 + 0x50) < 0) {
    uVar4 = 0;
LAB_800af630:
    *(undefined2 *)(param_1 + 0x50) = uVar4;
  }
  else {
    if (0x7f < *(ushort *)(param_1 + 0x50)) {
      uVar4 = 0x7f;
      goto LAB_800af630;
    }
    *(ushort *)(param_1 + 0x50) = *(ushort *)(param_1 + 0x50);
  }
  *(char *)(param_1 + 0xc0) = (char)*(undefined2 *)param_2;
  if (*(int *)(param_1 + 0x60) != -1) {
    bVar2 = false;
    if (*(char *)(param_1 + 0x4a) == -1) goto LAB_800af6b4;
    uVar5 = (uint)*(byte *)(param_1 + 99);
    if (*(char *)(param_1 + 0x4b) == -1) {
      bVar2 = false;
      if (*(byte *)(uVar5 + 0x80158a80) == uVar5) {
        bVar2 = true;
      }
      goto LAB_800af6b4;
    }
    bVar2 = true;
    if (*(byte *)((uint)*(byte *)(param_1 + 0x4a) + (uint)*(byte *)(param_1 + 0x4b) * 0x10 +
                 -0x7fea7560) == uVar5) goto LAB_800af6b4;
  }
  bVar2 = false;
LAB_800af6b4:
  if (bVar2) {
    FUN_800ac69c(*(undefined1 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b),
                 *(undefined1 *)(param_1 + 0x51));
  }
  *param_2 = 4;
  uVar3 = FUN_800af1b0(param_1,param_2);
  return uVar3;
}
