/* FUN_800761ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800761ac  body 0x800761ac..0x800762af  size 260 B
 * body sha256 4ea8d1dd5b4a3d58776c4e38144eccf7f405b40620ff54dba72fd31888e48aed
 * provider record sha256 fb5eb2b0237749ec39a25225a6fdb5f51a10d91b4c5d49d0e16228b0258b882a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800761ac(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_800c52dc + 0x3100;
  if (-1 < DAT_80119ea9) {
    FUN_80075608(5,1);
    DAT_80119ea9 = -1;
  }
  iVar1 = (param_1 & 0xff) * 2;
  do {
    func_0x80004cfc(*(undefined2 *)(&DAT_80115e64 + iVar1),iVar2,1,"ARMS EDT");
    DAT_80119ea9 = FUN_800752dc(*(undefined2 *)(&DAT_80115df0 + iVar1),5,1);
    DAT_8011a298 = (&PTR_s__80115a30_0x68_80115e18)[param_1 & 0xff];
  } while (DAT_80119ea9 == -1);
  return;
}
