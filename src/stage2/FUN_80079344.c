/* FUN_80079344
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079344  body 0x80079344..0x800793a3  size 96 B
 * body sha256 d8fff745ea12a66abd30befad74a8afe887be42461cd73ec7e20c352e24ae738
 * provider record sha256 cb201fbf7009a0beca3e62a62411a6bdeb1a905d08823d8b77ddfccda072416e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079344(short param_1,short param_2,short param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((&DAT_8011a3a4)[iVar2 * 0x3c] != '\0') {
    uVar1 = (undefined2)((int)param_2 + (int)param_3 >> 1);
    (&DAT_8011a37e)[iVar2 * 0x1e] = uVar1;
    (&DAT_8011a37c)[iVar2 * 0x1e] = uVar1;
    FUN_80079260();
  }
  return;
}
