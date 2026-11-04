/* FUN_80075140
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075140  body 0x80075140..0x800752db  size 412 B
 * body sha256 c9e476ccc1d36b03250ba6de79cc811af1f650eb2c571e56ea0f0ad3587c447a
 * provider record sha256 997d6f7348f7f79d6a1c8e8197bae127be9361199005875e2a183908832c0df9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80075140(void)

{
  char cVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined2 uStack00000010;
  uint in_stack_00000014;
  
  iVar6 = 0;
  puVar2 = &DAT_8011a37c;
  cVar1 = DAT_8011a3a4;
  for (iVar5 = 0; (cVar1 != '\0' && (iVar5 < 0xf)); iVar5 = iVar5 + 1) {
    cVar1 = *(char *)(puVar2 + 0x32);
    puVar2 = puVar2 + 0x1e;
  }
  if (iVar5 == 0xf) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar4 = iVar5 * 0x3c;
  (&DAT_8011a3a4)[iVar4] = 1;
  *(undefined4 *)(&DAT_8011a3a6 + iVar4) = local_res0;
  *(undefined4 *)(&DAT_8011a3aa + iVar4) = local_res4;
  *(undefined4 *)(&UNK_8011a3ae + iVar4) = local_res8;
  *(undefined4 *)(&UNK_8011a3b2 + iVar4) = local_resc;
  *(undefined2 *)(&UNK_8011a3b6 + iVar4) = uStack00000010;
  uVar7 = in_stack_00000014;
  do {
    if ((in_stack_00000014 & 0xf) != 0) {
      in_stack_00000014 = in_stack_00000014 + 0xf & 0xfffffff0;
    }
    if (*(short *)((int)register0x00000074 + 2) == -1) {
      *(undefined4 *)((int)&DAT_8011a390 + iVar4) = 0;
    }
    else {
      iVar3 = func_0x80004cfc(*(undefined2 *)((int)register0x00000074 + 10),in_stack_00000014,0,
                              &DAT_800b99f0);
      uVar7 = uVar7 + iVar3;
      *(uint *)((int)&DAT_8011a390 + iVar4) = in_stack_00000014;
      in_stack_00000014 = uVar7;
    }
    iVar4 = iVar4 + 4;
    iVar6 = iVar6 + 1;
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + 2);
  } while (iVar6 < 4);
  return iVar5;
}
