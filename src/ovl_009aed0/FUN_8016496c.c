/* FUN_8016496c
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x8016496c  body 0x8016496c..0x80164bf7  size 276 B
 * body sha256 6b0c506f3b70863ada088dda04d7f987576cc05aa473aaab0d1fccd662d35fad
 * provider record sha256 eb53e244a12223815993126523b3e33c23cce579b158cca9e5440b83f97c38be
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80164ba8) */
/* WARNING: Removing unreachable block (ram,0x80164bc4) */
/* WARNING: Removing unreachable block (ram,0x80164bd4) */
/* WARNING: Removing unreachable block (ram,0x80164bcc) */
/* WARNING: Removing unreachable block (ram,0x80164bbc) */
/* WARNING: Removing unreachable block (ram,0x80164b60) */
/* WARNING: Removing unreachable block (ram,0x80164b68) */
/* WARNING: Removing unreachable block (ram,0x80164b50) */

void FUN_8016496c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  *(undefined2 *)(param_1 + 0x2d0) = 0;
  uVar2 = (int)((*(byte *)(param_1 + 699) - 1) * 0x1000000) >> 0x18;
  *(undefined1 *)(param_1 + 0x2c4) = 0;
  if (uVar2 < 0x13) {
                    /* WARNING: Jumptable with 0 entries at 0x801649bc */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&PTR_LAB_80166038)[uVar2])();
    return;
  }
  if ((*(ushort *)(param_1 + 0x2b8) & 1) == 0) {
    iVar1 = FUN_80162870(4,&DAT_80166690,&DAT_80166694);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x26e) = 0;
    }
    else if ((*(ushort *)(param_1 + 0x26c) & 0x20) == 0) {
      *(undefined1 *)(param_1 + 0x26e) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x26e) = 2;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x26e) = 0;
  }
  return;
}
