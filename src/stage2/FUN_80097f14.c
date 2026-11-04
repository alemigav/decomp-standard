/* FUN_80097f14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097f14  body 0x80097f14..0x80097fcf  size 188 B
 * body sha256 6b39010455519c07731d92e393c9b722ba58d5941b2c8eff88807573f72910c4
 * provider record sha256 41d009ec073171c63afba2e5cddf42d2ffbffa3bb53583154b92be387a183a57
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097f14(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  
  iVar3 = 0x23;
  iVar1 = DAT_800c52dc + 0x3bd48;
  puVar2 = (undefined2 *)(DAT_800c52dc + 0x3bd52);
  do {
    iVar3 = iVar3 + -1;
    FUN_80047b04(iVar1,0);
    FUN_8004786c(iVar1,0x80,0x80,0x80);
    FUN_800478ac(iVar1,0x50,0x96);
    FUN_800479bc(iVar1,0x30,0x30);
    *(undefined **)(puVar2 + 1) = &DAT_8012f530;
    *puVar2 = 0x200;
    puVar2 = puVar2 + 10;
    iVar1 = iVar1 + 0x14;
  } while (iVar3 != 0);
  return;
}
