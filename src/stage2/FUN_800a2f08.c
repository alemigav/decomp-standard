/* FUN_800a2f08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2f08  body 0x800a2f08..0x800a3093  size 396 B
 * body sha256 8b90e8e2f3319003f57815c474637dbee905a04f4419572ad23cef285cbd885b
 * provider record sha256 df871e63b632e1768af7c3509f34c679bcf27e1ede696076851ec38fca2341e8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a2f08(int param_1,uint param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  float fVar3;
  uint uVar4;
  
  uVar4 = ((param_2 & 0xffff) * 32000) / _DAT_80143f04;
  if (_DAT_80143f04 == 0) {
    trap(0x1c00);
  }
  if ((*(char *)(param_1 + 1) == '\0') && (*(char *)(param_1 + 0x5c) != '\x03')) {
    *(undefined1 *)(param_1 + 0x5c) = 3;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined2 *)(param_1 + 0x48) = *(undefined2 *)(param_1 + 0x28);
  }
  else if (*(ushort *)(param_1 + 0x48) <= *(ushort *)(param_1 + 0x50)) {
    bVar1 = *(byte *)(param_1 + 0x5c);
    if (bVar1 == 1) {
      uVar2 = *(undefined4 *)(param_1 + 0x24);
      *(undefined1 *)(param_1 + 0x5c) = 2;
      *(undefined4 *)(param_1 + 0x58) = uVar2;
      *(undefined4 *)(param_1 + 0x54) = uVar2;
      *(undefined4 *)(param_1 + 0x4c) = uVar2;
      return;
    }
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined1 *)(param_1 + 0x5c) = 1;
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x58) = 0x3f800000;
        *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x24);
        *(undefined2 *)(param_1 + 0x48) = *(undefined2 *)(param_1 + 0x22);
      }
    }
    else if (bVar1 == 3) {
      *param_3 = 0;
      *(undefined4 *)(param_1 + 0x4c) = 0;
      return;
    }
  }
  if (*(short *)(param_1 + 0x48) == 0) {
    fVar3 = 1.0;
  }
  else {
    fVar3 = (float)*(int *)(param_1 + 0x50);
    if (*(int *)(param_1 + 0x50) < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    fVar3 = fVar3 / ((float)*(ushort *)(param_1 + 0x48) * 65536.0);
  }
  *(uint *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + uVar4 * 0x800;
  *(float *)(param_1 + 0x4c) =
       (*(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x58)) * fVar3 +
       *(float *)(param_1 + 0x58);
  return;
}
