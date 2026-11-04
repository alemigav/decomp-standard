/* FUN_8002cb54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002cb54  body 0x8002cb54..0x8002cc53  size 256 B
 * body sha256 821199e5391b2c0dd1eca005bb0a091ec35ff52b571afa338bde1125690e85ee
 * provider record sha256 e90af10ab811aebab8516d3967cf6b462b98beda5b4b1fab0bb286232e16d1a8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002cb54(int *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = (undefined4 *)param_1[5];
  pbVar3 = (byte *)*puVar4;
  iVar2 = puVar4[1];
  if (iVar2 == 0) {
    iVar2 = (*(code *)puVar4[3])();
    if (iVar2 == 0) {
      return 0;
    }
    pbVar3 = (byte *)*puVar4;
    iVar2 = puVar4[1];
  }
  iVar2 = iVar2 + -1;
  bVar1 = *pbVar3;
  pbVar3 = pbVar3 + 1;
  if (iVar2 == 0) {
    iVar2 = (*(code *)puVar4[3])(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    pbVar3 = (byte *)*puVar4;
    iVar2 = puVar4[1];
  }
  uVar5 = (uint)*pbVar3;
  if ((bVar1 != 0xff) || (uVar5 != 0xd8)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x2d;
    *(uint *)(*param_1 + 0x18) = (uint)bVar1;
    *(uint *)(*param_1 + 0x1c) = uVar5;
    (**(code **)*param_1)(param_1);
  }
  param_1[0x58] = uVar5;
  *puVar4 = pbVar3 + 1;
  puVar4[1] = iVar2 + -1;
  return 1;
}
