// Distributed under the MIT License.
// See LICENSE.txt for details.

#pragma once

#include <tuple>

#include "DataStructures/DataBox/DataBox.hpp"
#include "ParallelAlgorithms/LinearSolver/Tags.hpp"

/// \cond
namespace tuples {
template <typename...>
class TaggedTuple;
}  // namespace tuples
namespace Parallel {
template <typename>
struct GlobalCache;
}  // namespace Parallel
/// \endcond

namespace LinearSolver {
namespace Actions {

/*!
 * \brief Terminate the algorithm if the linear solver has converged.
 *
 * Uses:
 * - DataBox:
 *   - `LinearSolver::Tags::HasConverged<OptionsGroup>`
 */
template <typename OptionsGroup>
struct TerminateIfConverged {
  template <typename DbTagsList, typename... InboxTags, typename Metavariables,
            typename ArrayIndex, typename ActionList,
            typename ParallelComponent>
  static auto apply(db::DataBox<DbTagsList>& box,
                    tuples::TaggedTuple<InboxTags...>& /*inboxes*/,
                    const Parallel::GlobalCache<Metavariables>& /*cache*/,
                    const ArrayIndex& /*array_index*/,
                    const ActionList /*meta*/,
                    const ParallelComponent* const /*meta*/) noexcept {
    return std::tuple<db::DataBox<DbTagsList>&&, bool>(
        std::move(box),
        db::get<LinearSolver::Tags::HasConverged<OptionsGroup>>(box));
  }
};

}  // namespace Actions
}  // namespace LinearSolver
