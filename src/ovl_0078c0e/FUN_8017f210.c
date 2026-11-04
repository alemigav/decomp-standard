/* FUN_8017f210
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017f210  body 0x8017f210..0x8017f3b3  size 420 B
 * body sha256 d68c12e72e799540fe7e372cf835dee748f755eea3d41dbc05194502946cb241
 * provider record sha256 00b91d64b8026bf2b12de6fc0a2e156fc832fdd9c9a6137c235721f316be423b
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017f290) */
/* WARNING: Removing unreachable block (ram,0x8017f2b0) */
/* WARNING: Removing unreachable block (ram,0x8017f2c4) */
/* WARNING: Removing unreachable block (ram,0x8017f30c) */
/* WARNING: Removing unreachable block (ram,0x8017f31c) */
/* WARNING: Removing unreachable block (ram,0x8017f32c) */

undefined4 FUN_8017f210(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_80180ad4 = 6;
  FUN_8017fc34(DAT_80180d78,&DAT_80180da4,0xfeed,0xdeadbeef);
  DAT_80180ad4 = 7;
  FUN_8017f190(param_1);
  DAT_80180ad4 = 0xc;
  iVar1 = FUN_8017fdbc(DAT_80180d78);
  DAT_80180ad4 = 0xd;
  uVar2 = 3;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (iVar1 != 3) {
    uVar2 = FUN_8017fe54(DAT_80180d78);
    DAT_80180ad4 = 0xe;
  }
  return uVar2;
}
