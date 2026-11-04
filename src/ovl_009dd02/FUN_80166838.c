/* FUN_80166838
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166838  body 0x80166838..0x80166907  size 208 B
 * body sha256 00fb401ca3145188cddd7451239996ff4bf7e4ea878aeb2fae3035e0c99586f7
 * provider record sha256 bd58140b55030b231b314c93bf6219ba234963f686734427b6db5ec4aecf87bf
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80166838(undefined4 param_1)

{
  int iVar1;
  short *psVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  puVar3 = &DAT_801671d0;
  uVar4 = 0;
  psVar2 = &DAT_801671d2;
  while( true ) {
    iVar1 = FUN_801666c8(param_1,&DAT_800e1130,*puVar3,(int)*psVar2);
    if (iVar1 != 0) {
      return 1;
    }
    if (((_DAT_800e110c & 0x10000000) != 0) &&
       (iVar1 = FUN_801666c8(param_1,_DAT_800e13ec,*puVar3,(int)*psVar2), iVar1 != 0)) break;
    psVar2 = psVar2 + 2;
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 2;
    if (3 < uVar4) {
      return 0;
    }
  }
  return 1;
}
