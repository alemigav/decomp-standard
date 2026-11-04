/* FUN_8000b700
 * image   boot (boot), base 0x80000480
 * address 0x8000b700  body 0x8000b700..0x8000b7b3  size 180 B
 * body sha256 1ebaf2149f7ddca797a73da4eca87647578009f943ff7d5e8e0f9c457704c4b6
 * provider record sha256 f9856996e168772cf2a6b478b51dc0e86e7e51b13a2d3eb11098449113d4ae57
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000b700(undefined1 *param_1,undefined2 *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint *puVar5;
  undefined1 uVar7;
  uint uVar6;
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  
  uVar6 = 0;
  uVar7 = 0;
  puVar5 = (uint *)&DAT_80016470;
  uVar4 = 0;
  if (DAT_80014f9c != 0) {
    puVar3 = param_2 + 1;
    do {
      uVar2 = puVar5[1];
      uVar1 = (*puVar5 >> 8 & 0xc0) >> 4;
      *(char *)((int)puVar3 + 1) = (char)uVar1;
      if (uVar1 == 0) {
        uStack_b = (undefined1)(uVar2 >> 0x10);
        local_c = (undefined1)(uVar2 >> 0x18);
        *param_2 = CONCAT11(uStack_b,local_c);
        uStack_a = (undefined1)(uVar2 >> 8);
        uVar6 = uVar6 | 1 << (uVar4 & 0x1f);
        *(undefined1 *)puVar3 = uStack_a;
      }
      uVar7 = (undefined1)uVar6;
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 2;
      puVar3 = puVar3 + 2;
      param_2 = param_2 + 2;
    } while ((int)uVar4 < (int)(uint)DAT_80014f9c);
  }
  *param_1 = uVar7;
  return;
}
