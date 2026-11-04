/* FUN_800a57dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a57dc  body 0x800a57dc..0x800a588f  size 180 B
 * body sha256 464068ebc8261fdafca9a48a054f65b5ad3b5155603d304e1f342aaec72a9c1e
 * provider record sha256 0903b5e98f7d7a960a21d42851e1828865ed99e1ecf9334d923c525fa664a69a
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a57dc(undefined4 *param_1,undefined2 param_2,undefined2 param_3,uint param_4)

{
  undefined1 uVar1;
  
  FUN_800a5794();
  _DAT_80143f04 = func_0x800113e0(*param_1);
  *param_1 = _DAT_80143f04;
  uVar1 = 2;
  if ((((param_4 & 0x10000) == 0) && (uVar1 = 3, (param_4 & 0x20000) == 0)) &&
     (uVar1 = 4, (param_4 & 0x40000) == 0)) {
    uVar1 = (param_4 & 0x80000) == 0;
  }
  FUN_800a4dc4(param_1,param_2,param_3,uVar1);
  return 0;
}
