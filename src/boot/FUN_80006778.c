/* FUN_80006778
 * image   boot (boot), base 0x80000480
 * address 0x80006778  body 0x80006778..0x80006813  size 156 B
 * body sha256 4b405bc16d96d309c679cfd6a774366768d75100339a136c1507d35550466f30
 * provider record sha256 a1b96470ce0887522d4785f25adf0581e56e7ac16f2d7361ec7a5170a1b642b1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80006778(undefined2 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint *puVar5;
  undefined2 local_c;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  puVar5 = (uint *)&DAT_80014fa0;
  iVar4 = 0;
  if (DAT_80014f9c != 0) {
    puVar3 = (undefined1 *)((int)param_1 + 3);
    do {
      uVar2 = puVar5[1];
      uVar1 = (*puVar5 >> 8 & 0xc0) >> 4;
      puVar3[1] = (char)uVar1;
      if (uVar1 == 0) {
        local_c = (undefined2)(uVar2 >> 0x10);
        *param_1 = local_c;
        uStack_a = (undefined1)(uVar2 >> 8);
        puVar3[-1] = uStack_a;
        uStack_9 = (undefined1)uVar2;
        *puVar3 = uStack_9;
      }
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 2;
      puVar3 = puVar3 + 6;
      param_1 = param_1 + 3;
    } while (iVar4 < (int)(uint)DAT_80014f9c);
  }
  return;
}
