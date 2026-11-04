/* FUN_800777d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800777d8  body 0x800777d8..0x80077a7f  size 680 B
 * body sha256 93995c1d19bb56197ee83aa64cb184023dbee6d6cbc69cb61a459aceff512f1f
 * provider record sha256 e3ff94e0bec04bf5b5c52527983745f61a8ac6dfaf48d9cc261098c67098d4db
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800777d8(uint param_1)

{
  short sVar2;
  int iVar1;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  uint uVar6;
  
  uVar6 = param_1 >> 0x1c;
  if ((DAT_800e10ec & 0x2000) != 0) {
    return;
  }
  if ((&DAT_80119ee5)[uVar6 * 8] == -1) {
    return;
  }
  if ((&DAT_80119ee6)[uVar6 * 8] == -1) {
    return;
  }
  switch(param_1 >> 0x18 & 0xf) {
  default:
    goto switchD_8007786c_caseD_0;
  case 1:
    iVar1 = uVar6 * 8;
    pcVar5 = &DAT_80119ee4 + iVar1;
    FUN_80079344((int)(char)(&DAT_80119ee6)[iVar1],(int)(short)(&DAT_80119ee8)[uVar6 * 4],
                 (int)(short)(&DAT_80119ee8)[uVar6 * 4]);
    FUN_80078c48((int)(char)(&DAT_80119ee6)[iVar1],1,1,0);
    cVar4 = '\x01';
    break;
  case 2:
    iVar1 = uVar6 * 8;
    pcVar5 = &DAT_80119ee4 + iVar1;
    if (*pcVar5 == '\0') goto LAB_800779b4;
    sVar2 = FUN_80079418((int)(char)(&DAT_80119ee6)[iVar1],0);
    if (sVar2 != 0) {
      FUN_80079344((int)(char)(&DAT_80119ee6)[iVar1],0,0);
      FUN_800790a4((int)(char)(&DAT_80119ee6)[iVar1]);
    }
    cVar4 = '\x02';
    break;
  case 3:
    iVar1 = uVar6 * 8;
    pcVar5 = &DAT_80119ee4 + iVar1;
    FUN_80079344((int)(char)(&DAT_80119ee6)[iVar1],(int)(short)(&DAT_80119ee8)[uVar6 * 4],
                 (int)(short)(&DAT_80119ee8)[uVar6 * 4]);
    FUN_80078fc0((int)(char)(&DAT_80119ee6)[iVar1]);
    cVar4 = '\x01';
    break;
  case 4:
    iVar1 = uVar6 * 8;
    pcVar5 = &DAT_80119ee4 + iVar1;
    FUN_80079344((int)(char)(&DAT_80119ee6)[iVar1],0,0);
    FUN_80079194((int)(char)(&DAT_80119ee6)[iVar1]);
    cVar4 = '\x04';
    break;
  case 5:
    pcVar5 = &DAT_80119ee4 + uVar6 * 8;
    FUN_80078ee4((int)(char)(&DAT_80119ee6)[uVar6 * 8],0x7f,0x5a);
    cVar4 = '2';
  }
  *pcVar5 = cVar4;
switchD_8007786c_caseD_0:
LAB_800779b4:
  uVar3 = param_1 >> 0x10 & 0xff;
  if ((param_1 >> 8 & 0xff) != 0) {
    cVar4 = (char)(param_1 >> 8) + -1;
    if (uVar3 == 0) {
      iVar1 = uVar6 * 0x3c;
      (&DAT_8011a3a2)[iVar1] = cVar4;
      (&DAT_8011a3a1)[iVar1] = cVar4;
      (&DAT_8011a3a0)[iVar1] = cVar4;
      cVar4 = (&DAT_80119ee6)[uVar6 * 8];
    }
    else {
      if ((&DAT_8011a390)[uVar6 * 0xf + (uVar3 - 1)] == 0) {
        return;
      }
      (&UNK_8011a39f)[uVar3 + uVar6 * 0x3c] = cVar4;
      cVar4 = (&DAT_80119ee6)[uVar6 * 8];
    }
    FUN_80079260((int)cVar4);
  }
  return;
}
