/* FUN_80163b24
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163b24  body 0x80163b24..0x80163be7  size 196 B
 * body sha256 5e749c9d6a1962d64e2ed699a84ee1dc8f4ad9626f0b62390c86af2e5f2878b3
 * provider record sha256 6b7c15087175ce817ad9d8cbc39900d82c52bb56d18ec172fad7cd5cbc0e617b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163b24(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined1 uVar3;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x300;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if (sVar1 != 1) {
    return;
  }
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    if (2999 < *(uint *)(param_1 + 0x28c)) {
      uVar3 = 3;
      goto LAB_80163bd0;
    }
  }
  else if (2999 < (*(uint *)(param_1 + 0x290) & 0x3fffffff)) {
    uVar3 = 3;
    goto LAB_80163bd0;
  }
  uVar2 = func_0x80033604();
  uVar3 = 7;
  if ((0x340 >> (uVar2 & 0xf) & 1U) == 0) {
    uVar3 = 3;
  }
LAB_80163bd0:
  *(undefined1 *)(param_1 + 5) = uVar3;
  *(undefined2 *)(param_1 + 6) = 0;
  return;
}
