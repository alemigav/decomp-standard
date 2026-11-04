/* FUN_801712bc
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x801712bc  body 0x801712bc..0x8017131f  size 100 B
 * body sha256 32c46f720c447c2ec6f23de3dc244ed23b4a3a35b8e8e2c8db36d13690cd7a9e
 * provider record sha256 67ac012123e7ef5bd4d4863af52871bc828b05d0431cbe0daede65c063f24bcd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801712bc(undefined4 *param_1,int *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  puVar3 = (undefined2 *)*param_1;
  iVar6 = *param_2;
  do {
    uVar2 = 0;
    puVar4 = puVar3;
    do {
      puVar3 = puVar4 + 1;
      uVar1 = 1;
      if (((int)(uint)*(byte *)(iVar6 + uVar5) >> (uVar2 & 0x1f) & 1U) != 0) {
        uVar1 = 0xffff;
      }
      uVar2 = uVar2 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar3;
    } while (uVar2 < 8);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x28);
  *param_2 = iVar6 + 0x28;
  *param_1 = puVar3;
  return;
}
