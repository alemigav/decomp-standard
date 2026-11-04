/* FUN_801670b8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801670b8  body 0x801670b8..0x80167153  size 156 B
 * body sha256 7cc69264e5373388ca86401d25694086aeb7966be4ed324e11dd2b43aa65306e
 * provider record sha256 0bb21ebb323aca3572915c43617c2e98aafac852650c9dac32291122bc18599e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801670b8(uint *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  func_0x8004da40(param_1,param_1 + 10);
  *(undefined1 *)((int)param_1 + 0xd) = 0xff;
  puVar2 = (undefined4 *)&DAT_800e13f0;
  if (_DAT_800df93c != (undefined4 *)&DAT_800e13f0) {
    do {
      puVar1 = (uint *)*puVar2;
      if ((param_1 != puVar1) && ((*puVar1 & 1) != 0)) {
        func_0x8004d3a0(puVar1,param_1);
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != _DAT_800df93c);
  }
  return;
}
