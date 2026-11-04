/* FUN_80164d08
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80164d08  body 0x80164d08..0x80164e5b  size 340 B
 * body sha256 dba9aec8fc160a7786aecd9cb251a40e02b6e8ef25886c89aac4524ce618e230
 * provider record sha256 c094730ff6c62fe68048c67e76edff2e9afa718e97fb2c11be7284cc0588eab0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80164d30) */
/* WARNING: Removing unreachable block (ram,0x80164d34) */
/* WARNING: Removing unreachable block (ram,0x80164d80) */

void FUN_80164d08(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_38 [4];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [8];
  undefined1 auStack_10 [8];
  
  puVar2 = local_38;
  puVar1 = &DAT_80165f8c;
  do {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (puVar1 != &DAT_80165fbc);
  func_0x80037780(0x30f2000,0,&DAT_800e1ca4,local_38);
  func_0x80037780(0x30f3000,0,&DAT_800e1ca4,local_38 + 2);
  func_0x80037780(0x30f3000,0,&DAT_800e1ca4,auStack_28);
  func_0x80037780(0x30f2000,0,&DAT_800e1ca4,auStack_20);
  func_0x80037780(0x30f2000,0,&DAT_800e1ca4,auStack_18);
  func_0x80037780(0x30f3000,0,&DAT_800e1ca4,auStack_10);
  return;
}
