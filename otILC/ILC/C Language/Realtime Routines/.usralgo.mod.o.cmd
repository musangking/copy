cmd_/cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.o := powerpc-405-linux-gnu-gcc -Wp,-MD,/cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/.usralgo.mod.o.d  -nostdinc -isystem /usr/local/bin/../lib/gcc/powerpc-405-linux-gnu/4.2.2/include -Iinclude  -I/opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include -include include/linux/autoconf.h -D__KERNEL__ -Iarch/powerpc -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -fno-delete-null-pointer-checks -O2 -msoft-float -pipe -Iarch/powerpc -ffixed-r2 -mmultiple -mno-altivec -mno-spe -mspe=no -funit-at-a-time -mno-string -Wa,-m405 -fno-stack-protector -fomit-frame-pointer -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -O2 -DCONFIG_460EX -D_GNU_SOURCE -D_REENTRANT -D__XENO__ -mhard-float -I/usr/local/dtlibs/rtpmac -I/usr/local/dtlibs/libppmac -I/usr/local/dtlibs/libopener -I/opt/powerpc-405-rootfs/usr/local/xenomai-2.5.6/include -I/opt/powerpc-405-rootfs/usr/local/xenomai-2.5.6/include/posix -I/opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/include/xenomai -I/opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/include/xenomai/posix --sysroot=/opt/powerpc-405-rootfs  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(usralgo.mod)"  -D"KBUILD_MODNAME=KBUILD_STR(usralgo)"  -DMODULE -c -o /cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.o /cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.c

deps_/cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.o := \
  /cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.c \
    $(wildcard include/config/module/unload.h) \
  include/linux/module.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/markers.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  include/linux/poison.h \
  include/linux/prefetch.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbd.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/types.h \
    $(wildcard include/config/phys/64bit.h) \
  include/asm-generic/int-ll64.h \
  include/linux/posix_types.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/posix_types.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/processor.h \
    $(wildcard include/config/vsx.h) \
    $(wildcard include/config/ppc32.h) \
    $(wildcard include/config/ppc/prep.h) \
    $(wildcard include/config/task/size.h) \
    $(wildcard include/config/kernel/start.h) \
    $(wildcard include/config/ppc64.h) \
    $(wildcard include/config/4xx.h) \
    $(wildcard include/config/booke.h) \
    $(wildcard include/config/altivec.h) \
    $(wildcard include/config/spe.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/reg.h \
    $(wildcard include/config/40x.h) \
    $(wildcard include/config/fsl/emb/perfmon.h) \
    $(wildcard include/config/8xx.h) \
    $(wildcard include/config/apus/fast/except.h) \
    $(wildcard include/config/ppc/cell.h) \
    $(wildcard include/config/runlatch.h) \
  include/linux/stringify.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/cputable.h \
    $(wildcard include/config/mpc10x/bridge.h) \
    $(wildcard include/config/ppc/83xx.h) \
    $(wildcard include/config/8260.h) \
    $(wildcard include/config/ppc/mpc52xx.h) \
    $(wildcard include/config/bdi/switch.h) \
    $(wildcard include/config/power3.h) \
    $(wildcard include/config/power4.h) \
    $(wildcard include/config/ppc/pasemi/a2/workarounds.h) \
    $(wildcard include/config/44x.h) \
    $(wildcard include/config/e200.h) \
    $(wildcard include/config/e500.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/asm-compat.h \
    $(wildcard include/config/power4/only.h) \
    $(wildcard include/config/ibm405/err77.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/feature-fixups.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/reg_booke.h \
    $(wildcard include/config/403gcx.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/ptrace.h \
    $(wildcard include/config/softdisable.h) \
    $(wildcard include/config/ipipe.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/cache.h \
    $(wildcard include/config/ppc/e500mc.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/system.h \
    $(wildcard include/config/debugger.h) \
    $(wildcard include/config/kexec.h) \
    $(wildcard include/config/6xx.h) \
    $(wildcard include/config/booke/wdt.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/local/bin/../lib/gcc/powerpc-405-linux-gnu/4.2.2/include/stdarg.h \
  include/linux/linkage.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/linkage.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/first/bit.h) \
    $(wildcard include/config/generic/find/last/bit.h) \
    $(wildcard include/config/generic/find/next/bit.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/bitops.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/synch.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/find.h \
  include/asm-generic/bitops/sched.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/ipipe_base.h \
    $(wildcard include/config/ipipe/debug/context.h) \
    $(wildcard include/config/generic/clockevents.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/ipipe_base.h \
  include/linux/typecheck.h \
  include/linux/ratelimit.h \
  include/linux/param.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  include/linux/dynamic_debug.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/byteorder.h \
  include/linux/byteorder/big_endian.h \
  include/linux/swab.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/div64.h \
  include/asm-generic/div64.h \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
    $(wildcard include/config/x86.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/hw_irq.h \
    $(wildcard include/config/ipipe/trace/irqsoff.h) \
  include/linux/errno.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  include/linux/ipipe_trace.h \
    $(wildcard include/config/ipipe/trace.h) \
    $(wildcard include/config/ipipe/trace/panic.h) \
  include/asm-generic/cmpxchg-local.h \
  include/linux/stat.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/stat.h \
  include/linux/time.h \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/thread_info.h \
    $(wildcard include/config/ppc/256k/pages.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/page.h \
    $(wildcard include/config/ppc/64k/pages.h) \
    $(wildcard include/config/ppc/16k/pages.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/relocatable.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/ppc/std/mmu/64.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/kdump.h \
    $(wildcard include/config/crash/dump.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/page_32.h \
    $(wildcard include/config/physical/align.h) \
    $(wildcard include/config/not/coherent/cache.h) \
    $(wildcard include/config/pte/64bit.h) \
  include/asm-generic/page.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  include/linux/spinlock_types_up.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/generic/hardirqs.h) \
  include/linux/spinlock_up.h \
  include/linux/spinlock_api_up.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/atomic.h \
  include/asm-generic/atomic.h \
  include/linux/math64.h \
  include/linux/kmod.h \
  include/linux/gfp.h \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/highmem.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/unevictable/lru.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/wait.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/current.h \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/init.h \
    $(wildcard include/config/hotplug.h) \
  include/linux/section-names.h \
  include/linux/nodemask.h \
  include/linux/bitmap.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/string.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/linux/bounds.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/memory/hotremove.h) \
  include/linux/notifier.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/rwsem.h \
  include/linux/srcu.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/topology.h \
    $(wildcard include/config/pci.h) \
  include/asm-generic/topology.h \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/elf.h \
    $(wildcard include/config/spu/base.h) \
  include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/detect/softlockup.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/user/sched.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/x86/ptrace/bts.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/debug/stack/usage.h) \
    $(wildcard include/config/preempt/bkl.h) \
    $(wildcard include/config/group/sched.h) \
    $(wildcard include/config/mm/owner.h) \
  include/linux/capability.h \
    $(wildcard include/config/security/file/capabilities.h) \
  include/linux/timex.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/timex.h \
  include/linux/jiffies.h \
  include/linux/rbtree.h \
  include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/mmu/notifier.h) \
  include/linux/auxvec.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/auxvec.h \
  include/linux/prio_tree.h \
  include/linux/completion.h \
  include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/mmu.h \
    $(wildcard include/config/ppc/std/mmu.h) \
    $(wildcard include/config/ppc/book3e/mmu.h) \
    $(wildcard include/config/ppc/8xx.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/mmu-44x.h \
    $(wildcard include/config/ppc/early/debug/44x.h) \
    $(wildcard include/config/ppc/early/debug/44x/physlow.h) \
  include/linux/ipipe.h \
    $(wildcard include/config/debug/kernel.h) \
  include/linux/percpu.h \
    $(wildcard include/config/have/dynamic/per/cpu/area.h) \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
  include/linux/slub_def.h \
    $(wildcard include/config/slub/stats.h) \
    $(wildcard include/config/slub/debug.h) \
    $(wildcard include/config/kmemtrace.h) \
  include/linux/workqueue.h \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kref.h \
  include/trace/kmemtrace.h \
  include/linux/tracepoint.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/classic/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
  include/linux/rcuclassic.h \
    $(wildcard include/config/rcu/cpu/stall/detector.h) \
  include/linux/pfn.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/percpu.h \
  include/asm-generic/percpu.h \
    $(wildcard include/config/ipipe/debug/internal.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/percpu-defs.h \
  include/linux/ipipe_compat.h \
    $(wildcard include/config/ipipe/compat.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/ipipe.h \
    $(wildcard include/config/ppc/iseries.h) \
    $(wildcard include/config/ipipe/want/preemptible/switch.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/irq.h \
    $(wildcard include/config/.h) \
    $(wildcard include/config/irqstacks.h) \
  include/linux/radix-tree.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/time.h \
    $(wildcard include/config/power.h) \
    $(wildcard include/config/ppc/pasemi.h) \
    $(wildcard include/config/8xx/cpu6.h) \
  include/linux/ipipe_percpu.h \
    $(wildcard include/config/ipipe/domains.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/sem.h \
  include/linux/ipc.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/ipcbuf.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/sembuf.h \
  include/linux/signal.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/signal.h \
  include/asm-generic/signal.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/path.h \
  include/linux/pid.h \
  include/linux/proportions.h \
  include/linux/percpu_counter.h \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/seccomp.h \
  include/linux/unistd.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/unistd.h \
  include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  include/linux/resource.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  include/linux/latencytop.h \
  include/linux/cred.h \
    $(wildcard include/config/security.h) \
  include/linux/key.h \
    $(wildcard include/config/sysctl.h) \
  include/linux/sysctl.h \
  include/linux/aio.h \
    $(wildcard include/config/aio.h) \
  include/linux/aio_abi.h \
  include/linux/uio.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
  include/linux/marker.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/local.h \
  /opt/powerpc-405-rootfs/usr/src/linux-2.6.30.3-xeno-2.5.6/arch/powerpc/include/asm/module.h \
    $(wildcard include/config/dynamic/ftrace.h) \
  include/linux/vermagic.h \
  include/linux/utsrelease.h \

/cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.o: $(deps_/cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.o)

$(deps_/cygdrive/c/Users/lenovo/DOCUME~1/POWERP~2/ILC/ILC/CLANGU~1/REALTI~1/usralgo.mod.o):
