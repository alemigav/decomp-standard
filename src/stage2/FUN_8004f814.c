/* FUN_8004f814
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f814  body 0x8004f814..0x8004f8cb  size 184 B
 * body sha256 ceecd5eef3e267911be34ee712469e7400663dcaec3ab820c8ec14a285e8f848
 * provider record sha256 9d7961483138a14ecf5e729d10f33f2f7425a81f724770ea7367d64eb5f720a1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004f814(undefined4 param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((*param_2 & 2) == 0) && (puVar2 = &DAT_800e13e8, DAT_800df93c != &DAT_800e13e8)) {
    do {
      if ((param_2 != (uint *)*puVar2) &&
         (((*(uint *)*puVar2 & 1) != 0 && (iVar1 = FUN_8004d918(param_1,param_2), iVar1 != 0)))) {
        return 1;
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != DAT_800df93c);
  }
  return 0;
}
