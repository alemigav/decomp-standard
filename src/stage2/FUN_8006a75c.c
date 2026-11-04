/* FUN_8006a75c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a75c  body 0x8006a75c..0x8006a7eb  size 144 B
 * body sha256 f09347a330665cf48471a6211d2916f193d6d832442e18e5143e50df35349948
 * provider record sha256 4c8cc3aaa5cc661e59103f6f782cf9f15b78604f93e66aa84432fddca611efdb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_8006a75c(undefined4 param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0x8001;
  local_c = 0;
  FUN_8008383c(0,param_1,&local_10,&local_10);
  iVar1 = (int)local_10._0_2_;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  uVar2 = 0x4000 < iVar1;
  iVar1 = (int)local_c._0_2_;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (0x4000 < iVar1) {
    uVar2 = 2;
  }
  return uVar2;
}
