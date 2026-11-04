/* FUN_8000e860
 * image   boot (boot), base 0x80000480
 * address 0x8000e860  body 0x8000e860..0x8000e917  size 184 B
 * body sha256 ff7754c9ab38f51495c3d73e8f2409aba88839145c793781da579dd88dee4c7d
 * provider record sha256 9be3568da6f8db228490c4779fc06df8333e8d5a5c7ed66fef5488a1eb8ba296
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000e860(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = EntryHi;
  setCopReg(0,EntryHi,EntryHi & 0xff | param_1 & 0xffffe000);
  Index = TLB_probe_for_matching_entry(EntryHi);
  if ((Index & 0x80000000) == 0) {
    EntryHi = TLB_read_indexed_entryHi(Index);
    EntryLo0 = TLB_read_indexed_entryLo0(Index);
    EntryLo1 = TLB_read_indexed_entryLo1(Index);
    PageMask = TLB_read_indexed_entryPageMask(Index);
    uVar4 = PageMask + 0x2000U >> 1;
    if ((uVar4 & param_1) == 0) {
      uVar2 = EntryLo0;
    }
    else {
      uVar2 = EntryLo1;
    }
    if ((uVar2 & 2) != 0) {
      iVar3 = (uVar2 & 0x3fffffc0) * 0x40 + (param_1 & uVar4 - 1);
      goto LAB_8000e90c;
    }
  }
  iVar3 = -1;
LAB_8000e90c:
  setCopReg(0,EntryHi,uVar1);
  return iVar3;
}
