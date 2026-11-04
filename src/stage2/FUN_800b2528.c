/* FUN_800b2528
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2528  body 0x800b2528..0x800b258b  size 100 B
 * body sha256 6ab7bda5a168a217003100110c4fa5eda625cefcb01850a9052f4deee2135f61
 * provider record sha256 674f556e8cab69ba4e53e8ad9938b76cf996cf42bd1439de0bdc28901dd6ed81
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b2528(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a7a8c(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
