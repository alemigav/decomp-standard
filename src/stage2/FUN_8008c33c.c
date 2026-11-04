/* FUN_8008c33c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c33c  body 0x8008c33c..0x8008c39f  size 100 B
 * body sha256 c059c54497537946928417939c7608950bbb30f31f46737ee9bd792c1ab87efd
 * provider record sha256 777b2d0622346d7ead58786d6d805b7c90374e884702424a72d2bb6715a60ba7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c33c(int param_1,undefined1 param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = param_1 * 4;
  cVar2 = (&DAT_800e8eca)[iVar1];
  if (cVar2 == '\x01') {
    (&DAT_800e8ec9)[(param_1 + 1) * 4] = param_2;
    cVar2 = (&DAT_800e8eca)[iVar1];
  }
  if (cVar2 == '\x02') {
    (&DAT_800e8ec9)[(param_1 + -1) * 4] = param_2;
  }
  (&DAT_800e8ec9)[iVar1] = param_2;
  return;
}
